#include <iostream>
#include <vector>


// Exception safety

// use - std::addressof if operator& overloaded

// std::move, std::move_if_noexcept
// std::forward - moves if value rvalue and don't move if lvalue

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
            AllocTraits::construst(arr + i, value);
        }
    }

    void reserve(size_t n) {
        if (n <= cap) return;

        T* newarr = AllocTraits::allocate(alloc, n);
        size_t i = 0;
        try {
            for (i = 0; i < sz; ++i) {
                AllocTraits::construct(alloc, newarr + i, std::move_if_noexcept(arr[i]));
            }
        } catch (...) {
            for (size_t j = 0; j < i; ++j) {
                AllocTraits::destroy(alloc, newarr + j);
            }
            AllocTraits::dealocate(newarr, n);
            throw;
        }

        for (int i = 0; i < sz; ++i) {
            AllocTraits::destroy(alloc, arr + i);
        }

        AllocTraits::dealocate(arr, sz);

        arr = newarr;
        cap = n;
    }

    void resize(size_t n, const T& value = T()) {
        if (n > cap) {
            reserve(n);
        }
        for (int i = sz; i < n; ++i) {
            AllocTraits::construct(alloc, arr + i, value);
        }
        if (n < sz) {
            sz = n;
        }
    }

    // Args: int, char*
    template <typename... Args>
    void emplace_back(const Args&... args) {
        if (cap == sz) {
            reserve(2 * sz);
        }
        AllocTraits::construct(alloc, arr + sz, std::forward<Args>(args)...);
        ++sz;
    }

    void push_back(const T& value) {
         if (cap == sz) {
            reserve(2 * sz);
        }
        AllocTraits::construct(alloc, arr + sz, value);
        ++sz;
    }

     void push_back(T&& value) {
         if (cap == sz) {
            reserve(2 * sz);
        }
        AllocTraits::construct(alloc, arr + sz, std::move(value));
        ++sz;
    }


    void pop_back() {
        --sz;
        AllocTraits::destroy(alloc, arr + sz - 1);
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