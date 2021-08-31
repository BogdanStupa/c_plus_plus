#include <iostream>
#include <string>


struct Mom {
    int a = 0;
    void f(double) {
        std::cout << "Mom\n";
    }

protected:
    void g(int) {
        std::cout << "Mom g\n";
    }
};

struct Son: Mom {
    int a = 1;
    // using Mom; CE
    using Mom::f;
    using Mom::g; // if g was declarated in private scope we can't write this
    void f(int) {
        std::cout << "Son\n";
    }
    void g(std::string) {
        std::cout << "Son g\n";
    }
};


int main() {
    Son s;
    s.f(0.0);
    s.g(1);
    return 0;
}