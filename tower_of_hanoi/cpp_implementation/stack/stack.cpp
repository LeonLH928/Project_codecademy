#include <climits>
#include "stack.hpp"
Node::Node(int val, Node *next)
    : value(val), next(next)    {}
Node* Node::getNextNode() {
    return this->next;
}
int Node::getValue() {
    return this->value;
}
void Node::setNextNode(Node *new_next) {
    this->next = new_next;
}
Stack::Stack(std::string name, int limit)
    :   top_item(nullptr), size(0), limit(limit), name(name) {}
bool Stack::hasSpace() {
    return this->limit > this->size;
}
bool Stack::isEmpty() {
    return this->size == 0;
}
void Stack::push(int val) {
    if (this->hasSpace()) {
        Node *new_top = new Node(val);
        new_top->setNextNode(this->top_item);
        this->top_item = new_top;
        this->size++;
    }
    else {
        std::cout << "No space to add more!\n";
    }
}
int Stack::pop() {
    if (!this->isEmpty()) {
        Node *removed_item = this->top_item;
        this->top_item = removed_item->getNextNode();
        this->size--;
        int removed_value = removed_item->getValue();
        delete removed_item;
        return removed_value;
    }
    std::cout << "Nothing to remove! Return INT_MIN\n";
    return INT_MIN;
}
int Stack::peek() {
    if (!this->isEmpty()) {
        return this->top_item->getValue();
    }
    std::cout << "Nothing to peek! Return INT_MIN\n";
    return INT_MIN;
}
int Stack::getSize() {
    return this->size;
}
std::string Stack::getName() {
    return this->name;
}
void Stack::printCurrentDisks() {
    Node *top = this->top_item;
    std::cout << "Top -> bottom: ";
    while (top != nullptr) {
        std::cout << top->getValue() << " ";
        top = top->getNextNode();
    }
}
Node* Stack::getNthItemFromBottom(int nth) {
    if (nth > this->size) {
        return nullptr; // no such items exist
    }
    else if (nth == this->size) {
        return this->top_item;
    }
    
    int nth_from_top = this->size - nth + 1;
    int count = 1;
    Node *top = this->top_item;
    while (count < nth_from_top) {
        count++;
        top = top->getNextNode();
    }
    return top;
}