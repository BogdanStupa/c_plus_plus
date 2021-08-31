#include <iostream>

struct Granny {
    int g = 0;
};

struct Mom: public Granny {
    int m = 1;
    void f() { std::cout<< "Mom::f\n"; }

    Mom() { std::cout<<"Constructor-Mom\n"; }
};

//WARNING: direct base ‘Granny’ inaccessible in ‘Son’ due to ambiguity
// struct Son: public Mom, private Granny { // ---------------- the same behavior
struct Son: public Mom, public Granny {
    int s = 2;
    Son() { std::cout<<"Constructor-Son\n"; }
};


int main() {
    Son s;

    // s.g; // CE - ambiguous call 
    s.Mom::g; // OK
    // Granny is ambiguous
    // s.Mom::Granny::g; 
    // s.Granny::g; 

    return 0;
}