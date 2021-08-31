#include <iostream>

namespace not_virtual_functions {

struct Base {
    void f() { std::cout << "Base\n"; }
};

struct Derived: public Base {
    void f() { std::cout << "Derived\n"; }
};

}

namespace virtual_functions {

struct Base {
    virtual void f() { std::cout << "Base\n"; }
};

struct Derived: public Base {
    void f() { std::cout << "Derived\n"; }
};

}

int main() {
    {
        not_virtual_functions::Derived d;
        not_virtual_functions::Base& b = d;
        // Because it's not virtual, prints Derived and then Base
        d.f();
        b.f();
    }
    // Virtual functions such that which functions will be choosed independed from addres by we call this func
    {
        virtual_functions::Derived d;
        virtual_functions::Base& b = d;
        // Because it's virtual, prints Derived and then Derived
        d.f();
        b.f();
    }
    {
        virtual_functions::Derived d;
        virtual_functions::Base b = d;
        // Because b is a copy then prints Derived and Base
        d.f();
        b.f();
    }
    return 0;
}