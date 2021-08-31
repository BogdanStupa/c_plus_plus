#include <iostream>

template <typename T>
class C {
    C() = delete;
};


// decltype: expression -> its type
// declval: type -> expression of this type

// std::common_type implementation

template <typename Head, typename... Tail>
struct common_type {
    using type = typename common_type<Head, typename common_type<Tail...>::type>::type;
};


// if T or U haven't default constructor, then CE below
// but:
template <typename T>  
std::add_rvalue_reference_t<T> declval() noexcept;

template <typename T, typename U>
struct common_type<T, U> {
    using type = std::remove_reference_t<decltype(true ? declval<T>() : declval<U>())>; // expr don't calculates in decltype
};

template <typename... Types> 
using common_type_t = typename common_type<Types...>::type;

struct Granny  {

};

struct Mother: public Granny {

};

struct Father: public Granny{

};


int main() {
    C< common_type_t<Granny, Father> >();
    C< std::common_type_t<Mother, Father> >();
    return 0;
}