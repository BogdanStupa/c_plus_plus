#include <iostream>

// Virtual and non-virtual functions combined:

struct Base {
    virtual void f(int) { std::cout << "Base\n"; }
    void f(double) { std::cout << "Non-virtual base function\n"; }
};

struct Derived: public Base {
    int a = 1;
    void f(double) { std::cout << a << " Derived non virtual\n"; }
    void f(int) { std::cout << a << " Derived virtual\n"; }
};

struct GrandChild: public Derived {

};


namespace test {
    
    struct Mom {
        virtual void f() { std::cout << "Mom\n"; }
    };
    
    struct Dad {
        void f() { std::cout << "Dad\n"; }
    };

    struct Son: public Mom, public Dad {
        void f() { std::cout << "Son\n"; }
    };
}

// CE:
// namespace test_2 {
    
//     struct Base {
//         virtual void f(int) { std::cout << "Base\n"; }
//     };
    
//     struct Derived: public Base {
//         int f(int) { std::cout << "Derived\n"; }
//     };
    
// }

// WE SHOULD USE KEYWORD: OVERRIDE, because: 
namespace without_ovveride {
    
    struct Base {
        virtual void f(int) const { std::cout << "Base\n"; }
    };
    
    struct Derived: public Base {
        void f(int) { std::cout << "Derived\n"; }
    };
    
}


// With OVERRIDE: CE: 
// namespace with_ovveride {
    
//     struct Base {
//         virtual void f(int) const { std::cout << "Base\n"; }
//     };
    
//     struct Derived: public Base {
//         void f(int) override { std::cout << "Derived\n"; }
//     };
    
// }


// With OVERRIDE: CE: 
namespace with_final { // if we write final means that this function forbedden to override, will be CE 
// final can be applied to functions that only virtual 
    
    struct Base {
        virtual void f(int) const { std::cout << "Base\n"; }
    };
    
    struct Derived: public Base {
        void f(int) const override final { std::cout << "Derived\n"; } // will not be override, last(final) version of f 
    };
    
}


// How it works in complex multiple inharitance ?



// Virtual function such that decision of which function will be chosen make in runtime, 
// not in compile time, because behind pointers can lie somewhat which in compile time not clear
// This means that for shuch functions in compile time don't clear which function will be chosen,
// therefor in compile time compiler can't check on private in right way, in compile time compiler
// can check on type only for shuch func:

namespace proof_on_runtime_decision_making_with_virtual_functions {

struct Base {
public:
    virtual void f(int) const { std::cout << "Base\n"; }
};

struct Derived: public Base {  
private:  
    void f(int) const override { std::cout << "Derived virtual\n"; }
};

}


int main() {
    {
        Derived d;
        Base& b = d;
        
        d.f(0.0);
        b.f(0.0);

        d.f(0);
        b.f(0);

        d.Base::f(0);
        b.f(0);
    }

    {
        GrandChild c;
        Base& b = c;
        b.f(0);
    }

    {
        test::Son s;
        s.f(); 
        
        test::Mom& m = s;
        m.f();

        test::Dad& d = s;
        d.f();
    }

    {
        without_ovveride::Derived d;
        without_ovveride::Base b;
        d.f(0);
        b.f(0);
    }

    // {
    //     with_ovveride::Derived d;
    //     with_ovveride::Base b;
    //     d.f(0);
    //     b.f(0);
    // }    

    {
        proof_on_runtime_decision_making_with_virtual_functions::Derived d;
        proof_on_runtime_decision_making_with_virtual_functions::Base& b = d;
        // d.f(0); // CE
        b.f(0);
    }
    return 0;
}