class Node {
private:
    char *value;
    char *key;
    Node* next;
public:
    Node(char* value, char* key, Node *next = nullptr);
    Node* getNextNode(void);
    char* getValue(void);
    void setNewValue(char* new_value);
    char* getKey(void);
    void setNextNode(Node* next);
};
class LinkedList {
private:
    Node *head, *tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    void insert(char* value, char* key); //this will insert a new node into the end of the ll
    Node* find(char* key);
};