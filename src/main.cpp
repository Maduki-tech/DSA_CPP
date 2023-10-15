#include "LinkedList.h"
#include <iostream>
int main(int argc, char *argv[]) {
    LinkedList list;
    for (int i = 0; i < 10000; i++) {
        list.add(i);
    }

    std::cout << list.getSingleNode(80);

    return 0;
}
