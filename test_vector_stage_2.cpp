#include <iostream>
#include <vector>


// Exception safety

// use - std::addressof if operator& overloaded

template <typename T, typename Alloc = std::allocator<T>>
class Vector { 
private: 
    T* arr;
    size_t sz;
    size_t cap;
    Alloc alloc;

    using AllocTraits = std::allocator_traits<Alloc>;
public:

    Vector(size_t count, const T& value, const Alloc& alloc = Alloc()): alloc(alloc) {
        reserve(count);
        for (size_t i = 0; i < count; ++i) {
            // alloc.construct(arr + i, value);
            AllocTraits::construst(arr + i, value);
        }
    }

    void reserve(size_t n) {
        if (n <= cap) return;

        T* newarr = AllocTraits::allocate(alloc, n);
        // T* newarr = alloc.allocate(n);
        // T* newarr = reinterpret_cast<T*>(new char[n * sizeof(T)]); // char 1 - byte
        // T* newarr = new T[n];

        // size_t i = 0;

        try {
            std::uninitialized_move(arr, arr + sz, newarr);
        } catch (...) {
            AllocTraits::dealocate(newarr, n);
            // alloc.dealocate(newarr, n);
            //delete[] reinterpret_cast<char*>(newarr);
            throw;
        }
        
        // try {
        //     for (; i < sz; ++i) {
        //         AllocTraits::construct(alloc, newarr + i, arr[i]);
        //         // newarr[i] = arr[i]; // UB - because newarr[i] wasn't construct 
        //         // new(newarr + i) T(arr[i]); // placement new: in (newarr + i)-address put object type T - T(arr[i])
        //     }
        // } catch (...) {
        //     for (size_t j = 0; j < j; ++j) {
        //         AllocTraits::destroy(alloc, newarr + j);
        //         // (newarr + i)->~T();
        //     }
        //     AllocTraits::dealocate(newarr, n);
        //     // delete [] reinterpret_cast<char*>(newarr);
        //     throw;
        // } 

        // delete[] arr; // UB: calls destructors, because maybe not constructed objects 

        for (int i = 0; i < sz; ++i) {
            AllocTraits::destroy(alloc, arr + i);
        }

        AllocTraits::dealocate(arr, sz);

        // delete[] reinterpret_cast<char*>(arr); // reinterpret in order to don't call destructor
        arr = newarr;
        cap = n;
    }

    void resize(size_t n, const T& value = T()) {
        if (n > cap) {
            reserve(n);
        }
        for (int i = sz; i < n; ++i) {
            AllocTraits::construct(alloc, arr + i, value);
            // new (arr + i) T(value);
        }
        if (n < sz) {
            sz = n;
        }
    }

    template <typename... Args>
    void emplace_back(const Args&... args) {
        if (cap == sz) {
            reserve(2 * sz);
        }
        AllocTraits::construct(alloc, arr + sz, value);
        // new (arr + sz) T(value);
        ++sz;
    }

    void push_back(const T& value) {
         if (cap == sz) {
            reserve(2 * sz);
        }
        new (arr + sz) T(value);
        ++sz;
    }

     void push_back(T&& value) {
         if (cap == sz) {
            reserve(2 * sz);
        }
        new (arr + sz) T(std::move(value));
        ++sz;
    }


    void pop_back() {
        --sz;
        AllocTraits::destroy(alloc, arr + sz - 1);
        // (arr + sz)->~T();
    }

    T& operator[](size_t i) {
        return arr[i];
    }

    const T& operator[](size_t i) const  {
        return arr[i];
    } 

    T& at(size_t i) {
        if (i >= sz) {
            throw std::out_of_range("...");
        }
        return arr[i];
    }

    void shrink_to_fit() {

    }
};


template<>
class Vector<bool> {
private:
    uint8_t* arr;
    struct BitReference {
        uint8_t* bucket_ptr;
        uint8_t pos;

        BitReference& operator=(bool b) {
            if (b) {
                *bucket_ptr |= ((uint8_t)1 << pos);
            } else {
                *bucket_ptr &= ~((uint8_t)1 << pos);
            }
            return *this;
        }

        operator bool() const {
            return *bucket_ptr & (static_cast<uint8_t>(1) << pos);
        }
    };
    
public:
    BitReference operator[](size_t) {
        uint8_t pos = i % 8;
        uint8_t* ptr = arr + i /8;
        return BitReference(ptr, pos);
    }

};



class C {
public:
    template <typename U>
    C(const U&) = delete;
};

int main() {
    
    std::vector<bool> vb(10, false);
    vb[5] = true;

    C c(vb[5]);

    // bool& b = vb[5]; // CE
    const bool& b = vb[5];


    return 0;
}