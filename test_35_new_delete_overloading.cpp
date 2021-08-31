#include <iostream>
#include <cstddef> // size_t
#include <cstdlib> // malloc
#include <vector>


void* operator new(size_t n) {
    std::cout << "Allocated " << n << " bytes\n";
    return malloc(n);
}

void operator delete(void* ptr, size_t n) {
    std::cout << "Deallocated " << n << " bytes\n";
    free(ptr);
}

void* operator new[](size_t n) {
    std::cout << "Allocated array for " << n << " bytes\n";
    return malloc(n);
}

void operator delete[](void* ptr) {
    std::cout << "Deallocated array\n"; // << n << " bytes\n";
    free(ptr);
}

int main() {
    // {
    //     int* a = new int[10];
    //     delete[] a;

    //     double* pd = new double(1.2);
    //     delete pd;
    // }

    std::vector<int> v(5);
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    return 0;
}