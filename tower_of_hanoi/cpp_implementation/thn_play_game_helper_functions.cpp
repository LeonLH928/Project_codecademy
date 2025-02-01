#include <limits>
#include "stack/stack.hpp"

int pow(const int &num, const int &exp) {
    if (exp == 0) {
        return 1;
    }
    return num * pow(num, exp - 1);
}
void fixInstream(void) {
    if (std::cin.fail()) {
        std::cin.clear(); // set the instream state to normal
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the input buffer
        std::cout << "Invalid input. Please enter again: ";
    }
    else {
        std::cout << "Please enter an integer in proper ranges: ";
    }
}
void inputNumberOfDisks(int &num_disks) {
    std::cout << "Please enter the number of disks (should be >= 1): ";
    while (1) {
        std::cin >> num_disks;

        if (std::cin.fail() || num_disks < 1) {
            fixInstream();
        }   
        else {
            break;
        }
    }
}

void inputEither(int &either, std::string name) {
    std::cout << name << ": "; 
    while (1) {
        std::cin >> either;
        if (std::cin.fail() || !(either >= 1 && either <= 3)) {
            fixInstream();
        }
        else {
            break;
        }
    }
}
void inputStartAndEnd(int &start, int &end) {
    std::cout << "Please enter your starting rod and ending rod (1 is the left stack, 2 is the middle stack, and 3 is the right stack): \n\n";
    start = end = 0;
    while (start == end) {
        inputEither(start, "Starting rod");
        inputEither(end, "Ending rod");
        if (start == end) {
            std::cout << "You cannot have the same starting and ending rod. Please re-enter: \n";
        }
    }
}
void isReady(void) {
    std::cout << "If you are ready, press Enter to continue\n";
    std::cin.ignore();
    while (1) {
        if (std::cin.get() != '\n') {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "It's okay, you can continue by pressing Enter\n";
        }
        else {
            break;
        }
    }
}
void addingDisks(Stack* *stacks, const int &start, const int &num_disks) {
    for (int i = num_disks; i > 0; i--) { 
        stacks[start - 1]->push(i);
    }
}
void printStacksOfDisks(Stack* *stacks, const int &num_disks) {
    std::cout << "Left stack: \t\t Middle stack: \t\t Right stack:\n";
    for (int i = num_disks; i > 0; i--) { // i is the nth item from the bottom of the stack
        std::cout << '\t';
        for (int j = 0; j < 3; j++) {
            if (stacks[j]->getNthItemFromBottom(i) != nullptr) {
                std::cout << stacks[j]->getNthItemFromBottom(i)->getValue();
            }
            if (j == 0) {
                std::cout << "\t\t\t";    
            }
            else if (j == 1) {
                std::cout << "\t\t\t";    
            }
        }

        std::cout << '\n';
    }
}
bool isElementIn(char *letter, char check) {
    for (int i = 0; i < 3; i++) {
        if (letter[i] == check) {
            return true;
        }
    }
    return false;
}
Stack* getInputStack(Stack* *stacks) {
    char letter[] = {'L', 'M', 'R'};
    char input;
    while (1) {
        for (int i = 0; i < 3; i++) {
            std::cout << "Enter " << letter[i] << " for " << stacks[i]->getName() << '\n';
        }
        std::cin >> input;
        input = toupper(input);
        if (std::cin.fail() || !isElementIn(letter, input)) {
            if (std::cin.fail()) {
                fixInstream();
            }
            else {
                std::cout << "Please enter a proper letter:\n";
            }
        }
        else {
            break;
        }
    }
    Stack *input_stack = nullptr;
    for (int i = 0; i < 3; i++) {
        if (stacks[i]->getName()[0] == input) {
            input_stack = stacks[i];
            break;
        }
    }
    return input_stack;
}
void startPlaying(const int &num_disks, Stack* *stacks, const int &start, const int &end) {
    int player_num_moves = 0;
    while (stacks[end - 1]->getSize() != num_disks) {
        std::cout << "\n\n\n.........Current stacks\n";
        printStacksOfDisks(stacks, num_disks);
        while (1) {
            std::cout << "Which stack do you want to move from?\n";
            Stack* src_stack = getInputStack(stacks);
            std::cout << "Which stack do you want to move to?\n";
            Stack* des_stack = getInputStack(stacks);
            if (src_stack->isEmpty()) {
                std::cout << "You cannot move a disk from a stack without any disks. Please choose again:\n";
            }
            else if (des_stack->isEmpty() || des_stack->peek() > src_stack->peek()) {
                int disk = src_stack->pop();
                des_stack->push(disk);
                player_num_moves++;
                break;
            }
            else {
                std::cout << "You cannot move to another stack with a higher disk's value. Please choose again:\n";
            }
        }   
    }
    std::cout << "\n\nCongratulations!! You completed the game in " << player_num_moves << " moves, and the optimal number of moves is " << pow(2, num_disks) - 1;
}

