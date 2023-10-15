#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() { head = nullptr; }

LinkedList::~LinkedList() {
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::add(int value) {
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void LinkedList::remove(int value) {
    Node *current = head;
    Node *previous = nullptr;
    while (current != nullptr) {
        if (current->value == value) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
}

void LinkedList::print() {
    Node *current = head;
    while (current != nullptr) {
        std::cout << current->value << std::endl;
        current = current->next;
    }
}

int LinkedList::getSingleNode(int value) {
    Node *current = head;
    while (current != nullptr) {
        if (current->value == value) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}
