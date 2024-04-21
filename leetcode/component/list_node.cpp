#include <vector>
#include <iostream>
template <typename T>
struct Node {
    T val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(T x) : val(x), next(nullptr) {}
    Node(T x, Node *next) : val(x), next(next) {}
};

template<typename T>
Node<T>* generateListNode(std::vector<T> list){
    Node<T>* ret = new Node<T>();
    Node<T>* tmp = ret;
    for(T &e: list){
        ret->next = new Node<T>(e);
        ret = ret->next;
    }
    return tmp->next;
}

template<typename T>
void printNodes(Node<T>* head){
    while (head)
    {
        std::cout << head->val << " ";
        head=head->next;
    }
    std::cout << "\n";
}