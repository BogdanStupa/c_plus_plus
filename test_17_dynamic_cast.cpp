#include <iostream>


// dynamic_casts applies only to polimorthic types

struct Granny {
    int g;
    virtual void foo() {
        std::cout << "Granny\n";
    }
};

struct Mother: public Granny{
    int m;
    void foo() override {
        std::cout << "Mother\n";
    }
};

struct Father: public Granny {
    int f;
    void foo() override {
        std::cout << "Father\n";
    }
};

struct Son: public Mother, public Father {
    int s;
};

int main() {
    Son s;

    Mother* pm = &s;
    // Father* pf = pm; // CE
    // Father* pf = static_cast<Father*>(pm); // CE 
 

    Father* pf = dynamic_cast<Father*>(pm); // because pm is Son !!! 
    // if compiler in runtime discovered that really Mom and not Son, this cast returned nullptr
    
    pf->foo();


    Mother mom;

    try {
        Father& f = dynamic_cast<Father&>(mom); // throws std::bad_cast
    } catch (std::bad_cast err) {
        std::cerr << err.what() << std::endl;
    }
    // std::cout << typeid(pf).name() << std::endl;



    // {
    //     Mother* m;
    //     Father* pfm = dynamic_cast<Father*>(m);

    //     if (pfm != nullptr) {
    //         pfm->foo();
    //     }
    // }

    // {
    //     Son s;
    //     Mother* pm = &s;
    //     Father& f = s;
    //     Father* pf = &s;

    //     std::cout << typeid(pm).name() << std::endl;
    //     std::cout << typeid(f).name() << std::endl;
    //     std::cout << typeid(pf).name() << std::endl;
    // }
    return 0;
}


