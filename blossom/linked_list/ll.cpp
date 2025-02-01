#include <string.h>
#include <iostream>
#include "ll.hpp"
Node::Node(char* value, char* key, Node *next)
    : value(value), key(key), next(next) {}
Node* Node::getNextNode() {
    return this->next;
}
char* Node::getValue() {
    return this->value;
}
char* Node::getKey() {
    return this->key;
}
void Node::setNextNode(Node* next) {
    this->next = next;
}
void Node::setNewValue(char* new_value) {
    this->value = new_value;
}
void LinkedList::insert(char* value, char* key) {
    Node *new_node = new Node(value, key);
    if (this->head == nullptr) {
        this->head = this->tail = new_node;
        return;
    }
    
    this->tail->setNextNode(new_node);
    this->tail = new_node;
}
Node* LinkedList::find(char* key) {
    Node *current = this->head;

    while (current != nullptr) {
        if (strcmp(current->getKey(), key) == 0) {
            return current;
        }
        current = current->getNextNode();
    }
    return current;
}