#include <iostream>

void printMove(int start, int end) {
    std::cout << start << "->" << end << '\n';
}

void towerOfHaNoiImplementation(int num_disks, int start, int end) {
    if (num_disks == 1) {
        printMove(start, end);
    }
    else {
        int other = 6 - start - end;
        towerOfHaNoiImplementation(num_disks - 1, start, other);
        printMove(start, end);
        towerOfHaNoiImplementation(num_disks - 1, other, end);
    }
}

int main() {
    int n, s, e;
    std::cin >> n >> s >> e;
    while (!(n >= 1 && s >= 1 && s <= 3 && e >= 1 && e <= 3)) {
        std::cout << "Invalid input, pls reenter: ";
        std::cin >> n >> s >> e;    
    }
    towerOfHaNoiImplementation(n, s, e);
}