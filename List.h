#ifndef LIST_H
#define LIST_H

#include <stdexcept>

template <class T>
class List {
public:
    virtual ~List() = default;

    virtual void insert(int pos, const T& item) = 0;
    virtual void append(const T& item) = 0;
    virtual void prepend(const T& item) = 0;
    virtual T remove(int pos) = 0;

    virtual T& get(int pos) = 0;
    virtual const T& get(int pos) const = 0;

    virtual int search(const T& item) const = 0; // devuelve índice o -1
    virtual bool empty() const = 0;
    virtual int size() const = 0;
};

#endif

