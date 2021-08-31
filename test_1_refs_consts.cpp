#include <iostream>
#include <string>
#define en std::cout<<'\n'


int& test_1_1(int x) {
    // If we return reference on local value, then next things happens:
    // When we go out from this function, local value (y) destroys and compiler clear memory
    // but reference refer to died object
    int y = 2 * x;
    return y;
}

void test_1() {
    // Dangling reference 
    // Error because we tie x to dieded object(refer to rubbish) and initialize x  
    int x = test_1_1(1);
    std::cout<<x;
    en;
}


void test_2() {
    int x = 1;
    int* p = &x;
    // it's possible
    int*& pp = p;
}

void test_3_1(int&x, int& y) {
    int t = x;
    x = y;
    y = t;
}

void test_3() {
    // ERROR:
   // test_3_1(1, 2);
}



struct S_1 {
    int s;
};

struct S_2 {
    int& s;
};

void test_4() {
    std::cout<<sizeof(S_1)<<" "<<sizeof(S_2)<<std::endl;
    // Therefor doesn't make sence pass (int) by reference in function if we don't want to change him, 
    // because int weights 4byte, but reference on int weights 8byte
}


void test_5() {
    const std::string s = "abs";
    std::string ss = s;
    const std::string& rs = ss;
    // ERROR:
    // std::string& rs = s; 
}

const std::string test_6_1(const std::string s){
    return s;
}

void test_6() {
    // lifetime expansion
    const std::string& word = "a";
    // dangling reference
    test_6_1("efe")
}

void test_7() {
    int a = 1;
    const int* pa = &a; // pointer to const int
    ++pa; // we can !!!
    // *pa = 23; // we can't

    int* const cp = &a; // const pointer to int 
    // ++cp; // we can't
    *cp = 22; //we can

    const int* const ccp = p; // const pointer to const int


    {
        int x = 0;
        const int& y = x;
        // int& z = y; //CE
        x++;
        std::cout << y <<'\n'; // 1
    }
}


int main() {
    //it's possible: 
    const int& x = 1;
    // but is's not:
    // int& y = 1;
 
    test_1();
    test_2();
    test_4();
    test_5();

    return 0;
}