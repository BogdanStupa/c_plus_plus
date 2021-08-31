#include <iostream>

struct LineSegment {
    double begin;
    double end;

    double c_begin() { return 1.0; }
    double c_end() { return 2.0; }

};

void processSegment(LineSegment& s, bool inverted) {
    // double LineSegment::* begin = inverted ? &LineSegment::end : &LineSegment::begin;
    double LineSegment::* end = inverted ? &LineSegment::begin : &LineSegment::end;

    // or with methods:

    double (LineSegment::*begin)() = inverted ? &LineSegment::c_end : &LineSegment::c_begin;
    std::cout << (s.*begin)() << std::endl;

}

void processSegment_with_p(LineSegment* s, bool inverted) {
    double (LineSegment::*begin)() = inverted ? &LineSegment::c_end : &LineSegment::c_begin;
    std::cout << (s->*begin)() << std::endl;

}


int main(){
    double LineSegment::* p = &LineSegment::end;

    LineSegment s{12., 0.2};
    LineSegment ss{3., 3.3};

    std::cout << s.*p << " " << ss.*p <<std::endl;


    processSegment(s, true);
    processSegment_with_p(&ss, false);
}