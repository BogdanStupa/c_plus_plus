#include <iostream>
#include <vector>

template <typename T, template <typename> class Container = std::vector> // wait for template
struct Stack {
    Container<T> c;
};


template <typename Container> 
struct StackWithNonTemplateParams {
    Container c;
};

int main() {
    Stack<int> s;
    StackWithNonTemplateParams<std::vector<int> > ss;
}
