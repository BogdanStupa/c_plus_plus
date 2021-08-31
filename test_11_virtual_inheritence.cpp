#include <iostream>

// During inheritance we can ask don't create a copy base class if he already was inharitance by some class 
// Then make it inheritance virtual


struct Granny {
    int g = 0;
};

struct Mom: public virtual Granny {
    int m = 1;
};

struct Dad: public virtual Granny {
    int d = 2;
};

struct Son: public Mom, public Dad {
    int s = 3;
};


// During virtual inharitance we don't put base in beginning instead we put some ptr that pointer to vtable, 
// who knows whre are base class: 

// [ mom_ptr ]...[ Mom::m][ dad_ptr ]...[ Dad::d ][ Son::s ][ Granny::g ] -- 8 + 4 + 8 + 4 + 4 + 4 + (4 + 4) = 40 
            // ^-                 // ^- some paddings in otder to aline rule (4byte)                    ^- paddings
// A Granny puts in the end in order to avoid ambiduos 

int main() {
    Son s; // One copy af Granny then 
    s.g; // it'll works fine
    // BUT..... 
        // if inharitance is virtual then in dirived classes saved pointers to this base(to vtable), 
        // becuse he can be not in beggining

    std::cout << sizeof(s) << std::endl; // 40!!!!!!


    Dad* dad = &s; // Huge shifts to base pointers(to vtable and then to class) bad performance 
    // an object in memory does not lie intact


    // What if one inharitance to Granny will be virtual and other don't ??????? :
    // Will be one virtual Granny and one don't virtual 


// ========================================
    int t = 9;
    int* pt = &t;
    std::cout << sizeof(pt) << std::endl; // 8 byte

    return 0;
}