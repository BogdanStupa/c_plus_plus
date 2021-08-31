#include <iostream>


// void* - pointer to unknown in memory (don't allow adding or subtracting - warning), 
// some functions, for instance, malloc returns void*

// void - means, that function have nothing to return

// nullptr_t - nullptr

void test_pointers(){
    std::cout<< sizeof(int*)<<std::endl;
    int x;
    int* px = &x;
    int** ppx = &px;
    *px = 98;
    int*** pppx = &ppx;
    std::cout << x << ' ' << *px << ' ' << *ppx << ' ' << **ppx <<std::endl;
    std::cout << &x << ' ' << px << ' ' << ppx <<std::endl;
}

void f(double){}

void test_array_type(){
    int a[10];
    // f(&a);
    // f(a);// a converts to pointer to a
}

void test_array_like_pointers(){
    int a[100];
    int b[100];
    std::cout<< b - a<<" " << sizeof(a)<< "  " << &b <<std::endl;
}

void ff(double, int) {}

void test_pointer_to_function(){
    void (*pff)(double, int) = &ff;
    void (*pf)(double) = &f;

    std::cout<<"ff Function adress:" << &ff << " " << pff << " " << *pff << std::endl;
    std::cout<<"f Function adress:" << &f << std::endl;
    // Some example using this trick with pointer to function:
    // bool comp(int a, int b){return a > b; }
    // std::sort(v.begin(), v.end(), pcomp);
    // we also can write this:
    // std::sort(v.begin(), v.end(), comp); // but it's syntax suggar 
}


void g(float) { std::cout << "1" ;}
void g(int) { std::cout << "2"; }

void test_undefined_behavior_for_overloading_function() {
    g(0);
    g(0.0);
}

int main() {
    test_pointer_to_function();

}