#include "LinkedList.h"
#include <iostream>

/**
 * @brief creating a empty head with a null pointer
 */
LinkedList::LinkedList() { head = nullptr; }

/**
 * @brief deleting the linked list and removing all the nodes
 */
LinkedList::~LinkedList() {
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
    }
}

/**
 * @brief adding a new node to the linked LinkedList
 *
 * Explanation: if the head is null, then the new node will be the head.
 * Otherwise, the new node will be added to the end of the LinkedList.
 * @param value
 */
void LinkedList::add(int value) {
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

// Node will be the head
    if (head == nullptr) {
        head = newNode;
    } else {
        // current is the head
        Node *current = head;
        // while the next node is not null, keep going
        while (current->next != nullptr) {
            // current is the next node
            current = current->next;
        }
        // set last node to the new node
        current->next = newNode;
    }
}

/**
 * @brief removing a node from the LinkedList
 *
 * @param value the value of the node to be removed
 */
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
