#include <iostream>
#include <string.h>
#include <climits>
#include "../linked_list/ll.hpp"
#define MAX 50
unsigned int sumASCII(char *);
class HashMap {
private:
    LinkedList *array;
    size_t array_size;
public:
    HashMap(size_t array_size);
    int hash(char *key);
    int compress(int hash_code);
    void assign(char *key, char *value);
    char *retrieve(char *key);
};