#include <iostream>

// static types is a types that compiler can determinate them during compilation
// dynamic types is a types that compiler determinat in runtime (polymorphism)

// Type that has at least one vrtual function names Polymorphic type (and derivedes)
// For Polymorphic types supports RunTime Type Information - ompiler supply each polymorthic object


struct Base {
    virtual void f() {
        std::cout << "Base\n";
    }
};

struct Derived: public Base {
    void f() override {
        std::cout << "Derived\n";
    }
};


int main() {
    Derived d;
    Base& b = d; // Static type = Base, dynamic type = Derived !!!!
    b.f();

    {
        int n;
        std::cin >> n;
        Derived d;
        Base b;

        Base& bb = n % 2 ? d : b;

        // std::typeinfo
        std::cout << typeid(bb).name() << (typeid(bb) == typeid(b)) << std::endl;
    }
    
    return 0;
}