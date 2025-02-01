#include "thn_play_game_helper_functions.cpp"

int main() {
    std::cout << "Let's play Tower of Hanoi!\n\n";

    int num_disks;
    inputNumberOfDisks(num_disks);
    
    std::cout << "\n\nThe fastest way you can solve the problem is in " << pow(2, num_disks) - 1 << " ways.\n\n";

    Stack left_stack("Left", num_disks);
    Stack right_stack("Right", num_disks);
    Stack middle_stack("Middle", num_disks);

    Stack* stacks[] = {&left_stack, &middle_stack, &right_stack};

    int start, end;
    inputStartAndEnd(start, end);
    
    addingDisks(stacks, start, num_disks);

    isReady();

    startPlaying(num_disks, stacks, start, end);
}