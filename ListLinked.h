#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <iostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <class T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    ListLinked() : first(nullptr), n(0) {}

    ~ListLinked() override {
        while (first != nullptr) {
            Node<T>* tmp = first;
            first = first->next;
            delete tmp;
        }
    }

    void insert(int pos, const T& item) override {
        if (pos < 0 || pos > n)
            throw std::out_of_range("insert out of range");

        if (pos == 0) {
            first = new Node<T>(item, first);
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; ++i)
                prev = prev->next;
            prev->next = new Node<T>(item, prev->next);
        }
        ++n;
    }

    void append(const T& item) override {
        insert(n, item);
    }

    void prepend(const T& item) override {
        insert(0, item);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("remove out of range");

        Node<T>* to_delete;
        T value;

        if (pos == 0) {
            to_delete = first;
            first = first->next;
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; ++i)
                prev = prev->next;
            to_delete = prev->next;
            prev->next = to_delete->next;
        }

        value = to_delete->data;
        delete to_delete;
        --n;
        return value;
    }

    T& get(int pos) override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("get out of range");

        Node<T>* cur = first;
        for (int i = 0; i < pos; ++i)
            cur = cur->next;
        return cur->data;
    }

    const T& get(int pos) const override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("get out of range");

        Node<T>* cur = first;
        for (int i = 0; i < pos; ++i)
            cur = cur->next;
        return cur->data;
    }

    int search(const T& item) const override {
        Node<T>* cur = first;
        int i = 0;
        while (cur != nullptr) {
            if (cur->data == item)
                return i;
            cur = cur->next;
            ++i;
        }
        return -1;
    }

    bool empty() const override {
        return n == 0;
    }

    int size() const override {
        return n;
    }

    T& operator[](int pos) {
        return get(pos);
    }

    const T& operator[](int pos) const {
        return get(pos);
    }

    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const ListLinked<U>& l);
};

template <class U>
std::ostream& operator<<(std::ostream& os, const ListLinked<U>& l) {
    os << "[";
    Node<U>* cur = l.first;
    while (cur != nullptr) {
        os << cur->data;
        if (cur->next != nullptr) os << ", ";
        cur = cur->next;
    }
    os << "]";
    return os;
}

#endif

