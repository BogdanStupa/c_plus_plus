#include <iostream>

struct A {
    A() { std::cout<<"A" << "\n"; }
    ~A() { std::cout<<"~A" << "\n"; }
};

struct B {
    B() { std::cout<<"B" << "\n"; }
    ~B() { std::cout<<"~B" << "\n"; }
};

struct Granny {
    int z = 32;
    Granny() {
        std::cout << "Granny" << "\n";
    }
    ~Granny() {
        std::cout << "~Granny" << "\n";
    }
    Granny(int) {
        std::cout << "Granny int" << "\n";
    }
};


struct Mom: public Granny {
    A a;
    int y = 9;
    Mom() {
        std::cout << "Mom" << "\n";
    }
    ~Mom() {
        std::cout << "~Mom" << "\n";
    }

    Mom(int y): y(y) {
        std::cout<< y <<'\n';
    }
};

struct Son: public Mom {
    B b;
    int x = 0;
    Son() {
        std::cout << "Son" << "\n";
    }

    ~Son() {
        std::cout << "~Son" << "\n";
    }

    // Son(int x): x(x), Mom(x), Granny(7) {  type 'Granny' is not a direct base of 'Son'
    Son(int x): Mom(x), x(x) {
        std::cout<<"Son"<< x<<"\n";
    }
};



// ????????????
struct Daughter: public Mom {
    B b;
    int x = 0;

    //since c++11
    using Mom::Mom;
};

int main() {
    Son s(1);
    std::cout<<"\n\n";
    Daughter d();

    std::cout<<"\n\n";

    return 0;
}