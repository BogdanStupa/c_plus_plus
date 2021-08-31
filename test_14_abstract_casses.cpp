#include <iostream>
#include <vector>

// Abstract classes(interfaces) and pure virtual functions.

// Every classes that inharite abstract class must override all of abstract class methods


// Abstract class(we can't create objects of such type)
struct Base {
    // pure virtual function
    virtual void f(int)=0;
};


struct Son: public Base {
    void f(int) override {
        std::cout << "Son\n";
    }
};

struct Daughter: public Base {
    void f(int) override {
        std::cout << "Daughter\n";
    }
};



int main() {
    Son d;
    d.f(0);
    
    Base& b = d;
    b.f(0);


    {
        std::cout << "========\n";
        std::vector<Base*> v;
        // std::vector<Base&> v; // CE: (Base&* in vector) - std::reference_wrapper

        v.push_back(new Son());
        v.push_back(new Daughter());

        for (auto b: v) {
            b->f(0);
        }
    }


    return 0;
}