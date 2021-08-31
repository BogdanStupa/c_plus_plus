#include <iostream>


template <typename T>
struct S {
    T x;
};

template<>
struct S<int> {
    int y = 0;
};

template <typename T>
void f(T x) {
    std::cout << 1 << "\n";
}

template<>
void f(int x) {
    std::cout << 2 << "\n";
}

void f(int x) {
    std::cout << 3 << "\n";
}


template <typename T, typename U>
struct MyStruct {
    void f() {
        std::cout << 0 << "\n";
    }
};

template <typename T, typename U>
struct MyStruct<T&, U&> {
    void f() {
        std::cout << 1 << "\n";
    }
};

template <typename T>
struct MyStruct<T, T> {
    void f() {
        std::cout << 2 << "\n";
    }
};

int main() { 
    MyStruct<int&, double&>  s;
    s.f();   
    f(0);

    return 0;
}