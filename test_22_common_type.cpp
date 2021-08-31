#include <iostream>
#include <type_traits>


struct Base {
    virtual void f() {}
};

struct Son: public Base { };

struct Daughter: public Base { };


int main() {
    typename std::common_type<Son, Daughter>::type zz;
    typename std::common_type_t<decltype(x), decltype(y)> z;
}
