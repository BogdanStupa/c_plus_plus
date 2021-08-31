#include <iostream>

template <typename T>
class allocator {
public:
    T* allocate(size_t count) const {
        return ::operator new(count * sizeof(T)); // global operator new
    }

    void deallocate(T* ptr, size_t) {
        ::operator delete(ptr);
    }

    template<typename... Args>
    void construct(T* ptr, const Args&... args) {
        new(ptr) T(args...);
    }

    void destroy(T* ptr) {
        ptr->~T();
    }
};

int main() {

    return 0;
}