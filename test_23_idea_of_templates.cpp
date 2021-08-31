#include <iostream>
#include <unordered_map>


template <typename T>
T my_max(T a, T b) {
    return a > b ? a : b;
}


template <typename T>
struct S {
    /* data */
};

// since c++11
template <typename T>
using umap = std::unordered_map<T, T>;

// since c++14
template <typename T>
T pi = 3.14;


int main() {
    // For each call of template function, compiler creates a new copy of this finctions with appropriates parametes
    int (*pfi)(int, int) = &my_max<int>;
    double (*pfd)(double, double) = &my_max<double>;

    std::cout << (int*)pfi << " " << (int*)pfd << std::endl;

}