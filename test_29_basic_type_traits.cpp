#include <iostream>
#include <type_traits> // since c++11


template <typename T, typename U>
struct is_same {
    static const bool value = false;
};

template <typename T>
struct is_same<T, T> {
    static const bool value = true;
};

// since c++17 - template variebles
template <typename T, typename U>
const bool is_same_v = is_same<T, U>::value;

//Detect if U == T, typeinfo is bad because it's compute in runtime, but we can do it in compile time:
template <typename T, typename U>
void f() {
    std::cout << (is_same<T, U>::value ? 1 : 2) << std::endl;
}

// ====================================================================================================

template <typename T>
struct remove_const {
    using type = T;
};


template <typename T> // partial specialization
struct remove_const<const T> {
    using type = T;
};

// since c++14

template <typename T>
using remove_const_t = remove_const<T>::type;

// (Remove const from T) y = x   
template <typename T>
void g(T x) {
    // std::remove_const<T>::type y; // from traits
    // std::remove_const_t<T> y = x; // from traits 
    // std::decay<T> y = x;
}

// ====================================================================================================



int main() {


    f<int, int>();

    return 0;
}