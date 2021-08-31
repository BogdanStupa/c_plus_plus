#include <iostream>
#include <vector>
#include <string>

// auto keyword.

template <typename T, typename U>
auto f(const T& x, const U& y) {
    return x < y ? x : y;
}

template <typename T,   typename U>
auto& f1(const T& x, const U& y) {
    return x < y ? x : y;
}

void test_auto() {
    f('a', 2);
    // f1("d", 3); // CE

    int x = 0;
    auto&& y = x; // works like universal refs in template function
    // therefore now, y - lvalue refs to x (change y, change x)

    // const auto&& y1 = x; // not universal ref, CE

    // since c++17
    // structured binding
    std::pair<int, std::string> p{3, "scs"};
    auto [key, value] = p;
    auto& [keyr, valuer] = p;

    std::cout << key << " " << value;
}

// decltype 


// since c++11
template <typename Container>
auto get_at(Container& container, size_t index) -> decltype(container[index]) {
    // some additional logic
    return container[index];
}


// since c++14
template <typename Container>
decltype(auto) get_at(Container& container, size_t index) {
    // some additional logic
    return container[index];
}

template <typename T>
class C {
    C() = delete;
};

void test_decltype() {
    // decltype saved references, auto may collaps them 

    std::vector<int> v;
    get_at(v, 5) = 1;

    int x = 5;
    int& r = x;

    decltype(r) y = x; // int& y = x; 

    // decltype(expr)
    // if expr is lvalue of T, then decltype return t&
    // if expr is prvalue of T, then decltype return T
    // if expr is xvalue of T, then decltype return T&&


    C<decltype(++x)>(); // int&
    C<decltype(std::move(x))>(); // int&&
    C<decltype(x++)>(); // int

    // INTERESTING:
    C<decltype<(X)>>(); // int&

}




int main() {
    test_auto();
    test_decltype();

    return 0;
}