#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <iostream>
#include <stdexcept>
#include "List.h"

template <class T>
class ListArray : public List<T> {
private:
    T* arr;
    int max;
    int n;
    static const int MINSIZE = 2;

    void resize(int new_max) {
        if (new_max < MINSIZE) new_max = MINSIZE;
        T* tmp = new T[new_max];
        for (int i = 0; i < n; ++i) tmp[i] = arr[i];
        delete[] arr;
        arr = tmp;
        max = new_max;
    }

public:
    ListArray() : arr(new T[MINSIZE]), max(MINSIZE), n(0) {}

    explicit ListArray(int initial_max) : arr(nullptr), max(initial_max), n(0) {
        if (max < MINSIZE) max = MINSIZE;
        arr = new T[max];
    }

    ~ListArray() override {
        delete[] arr;
    }

    void insert(int pos, const T& item) override {
        if (pos < 0 || pos > n) throw std::out_of_range("insert: pos out of range");
        if (n == max) resize(max * 2);

        for (int i = n; i > pos; --i) arr[i] = arr[i - 1];
        arr[pos] = item;
        ++n;
    }

    void append(const T& item) override { insert(n, item); }

    void prepend(const T& item) override { insert(0, item); }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) throw std::out_of_range("remove: pos out of range");
        T removed = arr[pos];
        for (int i = pos; i < n - 1; ++i) arr[i] = arr[i + 1];
        --n;

        if (n <= max / 4 && max / 2 >= MINSIZE) resize(max / 2);
        return removed;
    }

    T& get(int pos) override {
        if (pos < 0 || pos >= n) throw std::out_of_range("get: pos out of range");
        return arr[pos];
    }

    const T& get(int pos) const override {
        if (pos < 0 || pos >= n) throw std::out_of_range("get: pos out of range");
        return arr[pos];
    }

    int search(const T& item) const override {
        for (int i = 0; i < n; ++i) {
            if (arr[i] == item) return i;
        }
        return -1;
    }

    bool empty() const override { return n == 0; }

    int size() const override { return n; }

    T& operator[](int pos) { return get(pos); }
    const T& operator[](int pos) const { return get(pos); }

    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const ListArray<U>& l);
};

template <class U>
std::ostream& operator<<(std::ostream& os, const ListArray<U>& l) {
    os << "[";
    for (int i = 0; i < l.n; ++i) {
        os << l.arr[i];
        if (i != l.n - 1) os << ", ";
    }
    os << "]";
    return os;
}

#endif

