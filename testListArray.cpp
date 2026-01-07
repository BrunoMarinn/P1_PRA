#include <iostream>
#include "ListArray.h"

int main() {
    ListArray<int> l;

    std::cout << "Lista vacia? " << (l.empty() ? "si" : "no") << std::endl;

    l.append(10);
    l.append(20);
    l.prepend(5);
    l.insert(1, 7);

    std::cout << "Lista: " << l << std::endl;
    std::cout << "Tamano: " << l.size() << std::endl;

    l.remove(2);
    std::cout << "Tras borrar pos 2: " << l << std::endl;

    std::cout << "Elemento en pos 1: " << l[1] << std::endl;

    int pos = l.search(20);
    std::cout << "20 esta en pos: " << pos << std::endl;

    return 0;
}

