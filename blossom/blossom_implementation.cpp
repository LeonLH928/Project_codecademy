#include "hash_map/hh.hpp"
#include "blossom.hpp"

int main() {
    HashMap blossom(14);
    for (int i = 0; i < 14; i++) {
        blossom.assign(flower[i], flower_meaning[i]);
    }

    char your_flower[50];
    std::cout << "Enter your flower: ";
    std::cin.getline(your_flower, 49);
    for (int i = 0; i < strlen(your_flower); i++) your_flower[i] = tolower(your_flower[i]); // handling case sensitivity 
    
    char *flower_def = blossom.retrieve(your_flower);
    
    if (flower_def != nullptr) {
        std::cout << "Your flower meaning is " << flower_def;
    }
    else {
        std::cout << "Oops! It seems that your flower is not in this list!";
    }
    
    return 0;
}