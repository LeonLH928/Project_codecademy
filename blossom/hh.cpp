#include "hh.hpp"
unsigned int sumASCII(char *s) {
    unsigned int len = strlen(s), sum = 0;
    for (int i = 0; i < len; i++) {
        sum += s[i];
    }
    return sum;
}
HashMap::HashMap(size_t array_size) {
    this->array_size = array_size;
    this->array = new LinkedList[array_size];
}
int HashMap::hash(char *key) {
    return sumASCII(key);
}
int HashMap::compress(int hash_code) {
    return hash_code % this->array_size;
}
void HashMap::assign(char *key, char *value) {
    int array_index = this->compress(this->hash(key));
    LinkedList &list_at_array = this->array[array_index];
    Node *payload = list_at_array.find(key);
    if (payload != nullptr) {
        payload->setNewValue(value);
        return;
    }
    list_at_array.insert(value, key);
}
char* HashMap::retrieve(char *key) {
    int array_index = this->compress(this->hash(key));
    LinkedList &list_at_array = this->array[array_index];
    Node *payload = list_at_array.find(key);
    if (payload == nullptr) {
        return nullptr;
    }
    return payload->getValue();
}