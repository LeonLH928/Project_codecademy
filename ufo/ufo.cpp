#include "ufo_functions.hpp"
int main() {
  char play_again;
  do {
    greet();
    std::string codeword = "";
    std::cout << "Please enter your word: ";
    std::getline(std::cin, codeword);
    std::string answer = "";
    for (int i = 0; i < codeword.size(); i++) {
      answer += "_";
    }
    int misses = 0;
    std::vector<char> incorrect;
    bool guess = false;
    char letter;
    while (answer != codeword && misses < 7) {
      display_misses(misses);
      display_status(answer, incorrect);
      std::cout << "Please enter your guess: ";
      std::cin >> letter;
      for (int i = 0; i < codeword.size(); i++) {
        if (letter == std::toupper(codeword[i]) || letter == std::tolower(codeword[i])) {
          answer[i] = letter;
          guess = true;
          break;
        }
      }
      if (guess == true) {
        std::cout << "Correct!" << '\n';
      }
      else {
        std::cout << "Incorrect! The tractor beam pulls the person in further.\n" ;
        incorrect.push_back(letter);
        misses++;
      }
      guess = false;
    }
    end_game(codeword, answer);
    std::cout << "Do you want to play again? Y (Yes) or N (No)";
    std::cin >> play_again;
    std::cin.ignore();
  } while (play_again == 'Y' || play_again == 'y');
 
  std::cout << "\nThank you for playing!\n";
}
