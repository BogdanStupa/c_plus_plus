#include <iostream>


struct S {
    int x = 0;
    double d = 0.0;

    S() {
        throw 1;
    }

    ~S() {

    }

    // operators for specific type:

    // static void* operator new(size_t n) {
    //     std::cout << "Allocated " << n << " bytes\n";
    //     return malloc(n);
    // }

    // static void operator delete(void* ptr) {
    //     std::cout << "Deallocated\n";
    //     free(ptr);
    // }
};

// placement new don't allocate memory, only call a constructor
// void* operator new(size_t, void* ptr) {
//     return ptr; 
// }



// nothrow operator new:
void* operator new(size_t n, std::nothrow_t) {
    return malloc(n);
}

// if we want to allocate objects in own way, similar with std::nothrow we can do it in such way:
struct my_new_t {};
my_new_t my_tag;

void* operator new(size_t n, my_new_t) {
    return malloc(n);
}

// if we create own operator new, we should create operator delete with same tag:

void operator delete(void* ptr, my_new_t) {
    std::cout << "I'm here !\n"; 
    free(ptr);
}


int main() {
    // S* s = new S();
    // delete s; 

    // nothrow operator new(don't  throw std::bad_alloc if can't allocate momory)
    // int* ptr = new(std::nothrow) int(0);


    try {
        // own new:
        S* ps = new(my_tag) S();
        // first call ~Destructor() because operator delete shouldn't call destructor, then 
        ps->~S();
        operator delete(ps, my_tag);
    } catch (...) {
        std::cout << "Caught\n";
    }

    return 0;
}