#include <iostream>

struct Base1 {
    int* bp = new int();

    ~Base1() {
        std::cout << "~Base1\n";
        delete bp;
    }
};

struct Base2 {
    int* bp = new int();

    virtual ~Base2() {
        std::cout << "~Base2\n";
        delete bp;
    }
};


struct Derived1: public Base1 {
    int* dp = new int();

    ~Derived1() {
        std::cout << "~Derived1\n";
        delete dp;
    }
};

struct Derived2: public Base2 {
    int* dp = new int();

    ~Derived2() {
        std::cout << "~Derived2\n";
        delete dp;
    }
};


struct Base3 {
    virtual ~Base3() = 0;
};

Base3::~Base3() {}

struct Derived3: public Base3 {
    int* dp = new int();

    ~Derived3() {
        std::cout << "~Derived1\n";
        delete dp;
    }
};

int main() {
    Base1* b1 = new Derived1();

    delete b1; // Which destructor ????? - Base, but should call Derived's destructor
    // delete bp occures, but dp don't
    
    // SOLUTIN: make destructor virtual
    Base2* b2 = new Derived2();
    delete b2;


    Base3* b3 = new Derived3();
    delete b3;

    return 0;
}