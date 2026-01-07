#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(const T& d, Node<T>* n = nullptr) : data(d), next(n) {}
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Node<T>& node) {
    os << node.data;
    return os;
}

#endif

