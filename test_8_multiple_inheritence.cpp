#include <iostream>

struct Mom {
    int m = 1;
    void f() { std::cout<< "Mom::f\n"; }

    Mom() { std::cout<<"Constructor-Mom\n"; }
};

struct Dad {
    int d = 2;
    void f() { std::cout<< "Dad::f\n"; }
    Dad() { std::cout<<"Constructor-Dad\n"; }

};

struct Son: public Mom, public Dad {
    int s = 3;
    Son() { std::cout<<"Constructor-Son\n"; }
};

// In MEMORY for class Son:
// [ Mom::m ][ Dad::d][ Son::s ]

int main() {
    Son s;

    std::cout<< &s.m << " " << &s.d << " "<< &s.s <<std::endl;
    // s.f() //CE: ambiguous f, we should cvalify which f we want to use:
    s.Mom::f(); 

    return 0;
}