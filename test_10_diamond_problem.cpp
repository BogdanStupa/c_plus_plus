#include <iostream>

struct Granny {
    int g = 0;
};

struct Mom: public Granny {
    int m = 1;
};

struct Dad: public Granny {
    int d = 2;
};

struct Son: public Mom, public Dad {
    int s = 3;
};


// In MEMORY for Son:
// [ Mom::g ][ Mom::m ][ Dad::g ][ Dad::d ][ Son::s ]
//                     ^ -- shift pointer when we create Dad from Son



// Question from interview:
// Why do objects in memory during inheritance lie like this: first parents, then heirs, and not vice versa?
// Answer:
    // Becacause for it doesn't need any time and proccess instructions, just pointer point to beggin:
    //  [ Mom::g ][ Mom::m ][ Son::s ]
    //  ^- point if we try to casts Son to Mom
    // In multimply inheritance: If it were the other way around, then each cast on the heir leads to a pointer shift.




// FIRST COMPILER DEFINE WHICH FIELDS OR METHODS IN PRIORITY AND THEN THEM ACCESSIBILITY
// THEREFOR PRIIVATE DOESN"T CHANGE AMBIGUOSLY !!!!

int main() {
    Son s;
    Dad* pd = &s; ///  VERY BAD, because there are points shift !!! 

    std::cout << &s << " " << pd << std::endl;

    // Son* ss = &pd; // CE: implicit cast to down 
    Son* son = static_cast<Son*>(pd); // inverse pointer shift

    // Granny& g = s; // CE: 'Grany' is ambiguos base of 'Son'
    // Granny* g1 = static_cast<Granny*>(&s); // CE
    // Granny* g2 = static_cast<Mom::Granny*>(&s) // also CE
    // How we can solve it:
        // First we can casts Son to Mom and then to Grannny or to Dad and then to Granny

    // 
    Granny& g = reinterpret_cast<Granny&>(s);


    // Dad& dad = reinterpret_cast<Dad&>(s); // UB: it's works, but formaly dad will be poiner to Mom, 
    // because any poinert shift don't occure !!!

    // std::cout<< &s << " " << &pd << "\n"; // 8 byte difference

    return 0;
}