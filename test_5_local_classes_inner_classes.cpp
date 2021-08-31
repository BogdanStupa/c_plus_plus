#include <iostream>

class C {
private:
    class Inner {
    public:
        int x = 12;
    };
public:
    Inner GetInner() {
        return Inner();
    }
};

int main() {
    C c;
    std::cout << c.GetInner().x << std::endl;

    // we can't write something like this:
    // Inner in = c.GetInner();  because class inner is'n visible in this scope
    // but we can write this:
    auto in = c.GetInner();


    // local classes: (for comparators)
    class Local {
    public:
        int x = 7;
    };

    Local l;

    std::cout << l.x <<std::endl;

    return 0;
}