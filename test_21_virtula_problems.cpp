#include <iostream>

// Some problems related to virtual dispatching.


namespace problem_with_params_by_default {
// 1) Params by default is the compile time conseption, 
// virtual functions - runtime: 

struct Base {
    virtual void f(int x = 1) const {
        std::cout << "Base: " << x << "\n";
    }
};

struct Derived: public Base {
    void f(int x = 2) const override {
        std::cout << "Derived: " << x << "\n";
    }
};

}

namespace problem_with_call_in_constructor {

struct Base {
    Base() { // <- when Base creates he doesn't known about Derived(vpointer not chenged) therefore here call f from Base 
        f(0);
    }

    virtual void f(int x) const {
        std::cout << "Base: " << x << "\n";
    }

    // or:
    // virtual void f(int x) const = 0;

};

struct Derived: public Base {
    Derived() {
        f(1);
    }

    void f(int x) const override {
        std::cout << "Derived: " << x << "\n";
    }
};

}

namespace problem_with_liker {
    
    struct Base {
        virtual void f();
    };

}

int main() {
    {
        const problem_with_params_by_default::Base& b = problem_with_params_by_default::Derived();
        b.f(); // Derived 1
    }
    {
        const problem_with_call_in_constructor::Base& b = problem_with_call_in_constructor::Derived();
        b.f(2);
    }
    {
        // problem_with_liker::Base b;
    }

    return 0;
}