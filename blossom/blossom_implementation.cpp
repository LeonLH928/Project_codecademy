#include "hh.hpp"
#include "blossom.cpp"

int main() {
    HashMap blossom(14);
    for (int i = 0; i < 14; i++) {
        blossom.assign(flower[i], flower_meaning[i]);
    }
    char *your_flower;
    std::cout << "Enter your flower: ";
    std::cin >> your_flower;
    char *flower_def = blossom.retrieve(your_flower);
    if (flower_def != nullptr) {
        std::cout << "Your flower meaning is " << flower_def;
    }
    else {
        std::cout << "Oops! It seems that your flower is not in this list!";
    }
    return 0;
}