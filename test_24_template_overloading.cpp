#include <iostream>


template<typename T, typename U>
void f(T x, U y) {
    std::cout << "1\n";
}

template<typename T>
void f(T x, T y) {
    std::cout << "2\n";
}

void f(int x, int y) {
    std::cout << "3\n";
}


template<typename T>
void g(T x) {
    std::cout << "1\n";
}

template<typename T>
void g(T& x) {
    std::cout << "2\n";
}

template<typename T>
void g(const T& x) {
    std::cout << "3\n";
}



template<typename T>
void h(T x) {
    std::cout << "1\n";
}

template<typename T, typename U = int>
void h(T x) {
    std::cout << "2\n";
}

template <typename T>
struct S {
    S() = default;

    template <typename U>
    S(U& x) {
        std::cout << 1 << "\n";
    }

    S(const S<T>&) {
        std::cout << 2 << "\n";
    }
};

int main() {
    f(0, 0);
    f<>(0, 0); // means that we want to call template functions despite exists non-template version

    int x = 8;
    // g(1); // ambiguos
    // g(x); // ambiguos   
    // g<const int&>(1); also C
    
    S<int> s;
    S<int> ss = s; // here will call not a copy constructor

    return 0;
}