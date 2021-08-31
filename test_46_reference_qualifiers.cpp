#include <iostream>
#include <string>


// qualifiers: const, non-const, ref-qualifiers(&, &&)

struct Data {
    Data(const std::string& s): data(s) {}

    std::string getData() & {  // means that this methods applies only to not-const lvalue
        std::cout << 1;
        return data;
    }

    std::string getData() && {  // means that this methods applies only to rvalue
        std::cout << 2;
        return std::move(data);
    }

    // BUT if:
    // std::string getData() const & {  // const lvalue reference can be binded to rvalue
    //     return data;
    // }


    // THIS CAN BE USEFULL WHEN WE CRETEATE operator=
    Data& operator=(const Data& another) & { // don't works with rvalue
        
    }

private:
    std::string data;
};

void f(Data&& x) {
    std::string s = std::move(x).getData();
    std::string ss = x.getData();
}

int main() {
    Data d("assd");

    f(std::move(d));

    return 0;
}