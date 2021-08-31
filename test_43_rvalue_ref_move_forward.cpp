#include <iostream>

// value categories not a types, it's syntax suggar

// std::move - cast lvalue to rvalue

// std::move_if_noexcept (noexcept important in move constructor, because in reserve will called copy constructs)

// std::forward - moves if value rvalue and don't move if lvalue

// std::conditional - analog ternar operator for types 

// how to check if functions is noexcept ? 

template <typename T>
std::remove_reference_t<T>&& move(T&& x) noexcept {
    return static_cast<std::remove_reference_t<T>&&>(x);
}


// if move-constructor is deleted, we should return false, but will generate CE

template <typename T>
T f() noexcept;

/*
template <typename T>
std::conditional_t<noexcept( T( f<T>() ) ), T&&, const T&> move_if_noexcept(T& x) noexcept {
    return std::move(x);
}
*/

template <typename T>
auto move_if_noexcept(T& x) noexcept
    -> std::conditional_t<noexcept( T( f<T>() ) ), T&&, const T&> {
    return std::move(x);
}


template <typename T>
T&& forward(std::remove_reference_t<T>& x) noexcept {
    return static_cast<T&&>(x);
} 

// one of overloadigs forward function
// template <typename T>
// T&& forward(std::remove_reference_t<T>&& x) {
//     static_assert(!std::if_lvalue_reference_v<T>);
//     return static_cast<T&&>(x);
// }  

// case of lvalue:
// T == type&
// typeof(x) == type&
// T&& == type&

// case of rvalue:
// T == type
// typeof(x) == type&
// T&& == type&&



void f(int&) {
    std::cout << 1;
} 

void f(int&&) {
    std::cout << 2;
} 

struct S {
    S() {
        std::cout << "Created!";
    }

    S(const S&) {
        std::cout << "Copy!";
    }

    S(S&&) noexcept {
        std::cout << "Move!";
    }

    ~S() {
        std::cout << "Destryed!";
    }
};

int main() {
    S s;

    S&& r = move_if_noexcept(s);

    {
        int a = 1;
        int& b = a;
        // int& c = 2; // CE

        // int&& d = a; // CE
        int&& h = std::move(b);

        int&& e = 55;
        f(e); // 1 : e-lvalue;
        f(std::move(e)); // 2 : now e - rvalue
    }
    return 0;
}