#include <iostream>
class Node {
private: 
    int value;
    Node *next;
public:
    Node(int val, Node *next = nullptr);
    Node *getNextNode(void);
    int getValue(void);
    void setNextNode(Node *new_next);
};

class Stack {
private:
    Node* top_item;
    int size;
    int limit;
    std::string name;
public:
    Stack(std::string name, int limit = 1000);
    bool hasSpace(void);
    bool isEmpty(void);
    void push(int val);
    int pop(void);
    int peek(void);
    int getSize(void);
    std::string getName(void);
    void printCurrentDisks(void);
    Node* getNthItemFromBottom(int nth);
};