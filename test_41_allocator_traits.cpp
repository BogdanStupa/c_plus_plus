#include <iostream>


// rebind_alloc for lists How allocator works in lists ?

// What is copy allocator ??? Copping and assigment allocators to each other.

template <typename T, typename Alloc = std::allocator<T>>
class list {
    struct Node {};
    std::allocator_traits<All>::rebind_alloc<Node> alloc;
public:
    list(const Alloc& alloc = Alloc()): alloc(alloc) {}

};

int main() {

    return 0;
}