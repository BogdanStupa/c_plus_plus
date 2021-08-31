#include <iostream>

// Casts between base and derived classes.


struct GrandBase { };

struct Base: public GrandBase {
    int a = 0;
    Base() = default;
    Base(const Base&) {
        std::cout<<"A";
    }
};

struct Derived: public Base {
    int a = 1;
    Derived()=default;
};


void f(Base b) {
    std::cout << b.a <<std::endl; 
}


// In MEMORY for Derived:
// [ Base ][ Derived ]
// GrandBase without any field an methods therefor it's applieds "Empty base optimization".

int main() {
    Derived d;
    Base& b = d;
    GrandBase& gb = d;
    std::cout << sizeof(d) << sizeof(b) << sizeof(gb) <<std::endl;
    f(d);
    
    std::cout<<*(&b.a + 1) << std::endl;


    // Derived dd = b; // here we should define constructor in Derived form Base

    return 0;
}