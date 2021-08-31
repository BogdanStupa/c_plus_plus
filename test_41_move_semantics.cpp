#include <iostream>


// std::move function

// Rvalue references, move-operations


class String {
private:
    char* arr;
    size_t sz;
    size_t cap;
public:
    String(const String& s);
    
    String(String&& s) arr(s.arr), sz(std::move(s.sz)), cap(s.cap)  noexcept {  // move constructor NOEXCEPT IMPORTANT IN MOVE CONSTRUCTOR
        s.arr = nullptr;
        s.sz = 0;
        sz.cap = 0;   
    }

    String& operator=(String&& s) { // move operator =
        String news(std::move(s));
        swap(news);
        return *this;
    }
};


template <typename T>
void swap(T& a,T& b) {
    T t = std::move(x);
    x = std::move(y);
    y = std::move(t);
}

int main() {

    return 0;
}