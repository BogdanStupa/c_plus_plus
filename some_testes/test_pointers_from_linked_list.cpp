#include <iostream>

template<typename T>
class Node {
public:
    T data;
    Node* next; 

    Node(): data(0), next(nullptr) {}
    Node(T data, Node* next=nullptr): data(data), next(next) {}
};


template<typename T = int>
void print(Node<T>* head) {
    while (head != nullptr){
        std::cout << head->data << "\t";
        head = head->next;
    }
    std::cout << "\n";
}

template<typename T>
void push_front(Node<T>** head_ref, T data) {
    std::cout << "Address of head adress:\t" << &head_ref << "\n"
              << "Address to head node:\t"<< (*head_ref) << "\n"
              << "Address to head:\t" << head_ref << "\n"
              << std::endl
              << std::endl;

    Node<T>* new_node = new Node<T>(data, *head_ref);
    (*head_ref) = new_node;
    
    std::cout << "Adress of new node:\t" << &new_node << "\n"
              << "Address to new head node:\t" << new_node << "\n" 
              << "Address to old head node:\t" << new_node->next << "\n"
              << std::endl 
              << std::endl;

}

template<typename T>
void insert_after(Node<T>* head, T data, int k) {
    if(k < 1) throw std::out_of_range("k < 1");
    for (int i = 0; i < k - 1; i++) {
        if (head == nullptr) throw std::out_of_range("k > ");
        head = head->next;
    }
    Node<T>* new_node = new Node<T>(data, head->next);
    head->next = new_node;
}

template<typename T>
void append(Node<T>* head, T data) {
    std::cout << "Address of head in func:\t" << &head << std::endl; 
    Node<T>* prev_head = head;
    while (head != nullptr) {
        prev_head = head;
        head = head->next;
    }
    Node<T>* n = new Node<T>(data);
    prev_head->next = n;
}   

template<typename T>
void push_front(Node<T>** head, Node<T>* node) {
    node->next = *head;
    *head = node;
}   



template<typename T = int>
void move_node(Node<T>** destNode, Node<T>** sourceNode) {
    Node<int>* newNode = (*sourceNode);
    (*sourceNode) = newNode->next;
    newNode->next = (*destNode);
    (*destNode) = newNode;

}   




int main() {
    Node<int>* head = new Node<int>(33);
    Node<int>* second = new Node<int>();
    Node<int>* third = new Node<int>();

    head->next = second;
    second->data = 11;
    second->next = third;

    std::cout << "Address of head:\t" <<&head << "\n"
              << "Address to head node:\t" << head << "\n"
              << "Adress of head node:\t" << head->next << "\n"
              << std::endl
              << std::endl;

    push_front<int>(&head, 44);
    // push_front<int>(&head, 99);
    print<int>(head);
    std::cout<< "\n";
    insert_after<int>(head, 97, 2);
    std::cout << "Address of head:\t" << &head << std::endl; 
    append<int>(head, 77);

    Node<int>* d = new Node<int>(9991);
    push_front(&head, d); 

    std::cout  << "=================\n";
    print<int>(head);
    std::cout << "\n=================\n";


    Node<int>* head1 = new Node<int>(33);
    Node<int>* second1 = new Node<int>(44);
    Node<int>* third1 = new Node<int>(8723);
    head1->next = second1;
    second1->next = third1;

    std::cout  << "=================\n";
    print<int>(head1);
    std::cout << "\n=================\n";

    // Node<int>** t = &head;
    // head = head1;
    // head1 = t;

    move_node(&head, &head1);

    std::cout  << "=================\n";
    print<int>(head);
    std::cout << "\n=================\n";
    std::cout  << "=================\n";
    print<int>(head1);
    std::cout << "\n=================\n";


    int val = 10;
    int* pval = &val;
    int** ppval = &pval;


    std::cout << "\n" << &pval << "\t" << pval << "\t" << *pval << "\t" << &val << "\n";
    std::cout << &ppval << "\t" << ppval << "\t" << (*ppval) << "\t" << (**ppval) << std::endl; 

    return 0;
}


