#include <cstdlib>
#include <iostream>

int main() {
  // Defining important ints
  int highestNumber = 100, inputNumber = 0, rounds = 1;
  int difficulty = 0;

  // Char that stores user approval
  char approval = '-';

  // seeding random integer generation
  srand(time(0));

  std::cout << "Are you up for a challenge? (N/Y): ";

  std::cin >> approval;

  if (approval == 'n' || approval == 'N') {
    std::cout << "See you soon! :)" << std::endl;
  }

  while (approval == 'y' || approval == 'Y') {

    std::cout << "Choose a Difficulty." << std::endl;
    std::cout << "1 / 2 / 3 : ";
    std::cin >> difficulty;

    if (difficulty == 1) {
      highestNumber = 100;
    } else if (difficulty == 2) {
      highestNumber = 500;
    } else if (difficulty == 3) {
      highestNumber = 1000;
    }

    while (difficulty < 1 || difficulty > 3) {
      std::cout << "Invalid difficulty! Please enter a valid difficulty."
                << std::endl;
      std::cout << "1 / 2 / 3 : ";
      std::cin >> difficulty;
    }

    // Defining random integer inside loop so it resets each round
    int targetNumber = rand() % highestNumber + 1;

    std::cout << "---------------------" << std::endl;
    std::cout << "Round: " << rounds << std::endl;
    std::cout << "---------------------" << std::endl;

    std::cout << "Please enter a number between 0 & " << highestNumber
              << std::endl;
    std::cout << "$: ";

    std::cin >> inputNumber;

    // Defining guessCount inside the loop so it resets
    int guessCount = 0;
    while (inputNumber != targetNumber) {

      if (difficulty == 1 && inputNumber > 100) {
        std::cout << "The number you entered was out of range!" << std::endl;
        std::cout << "---------------------" << std::endl;
        std::cout << "Please enter a number between 0 & " << highestNumber
                  << std::endl;
        std::cout << "$: ";

        std::cin >> inputNumber;

      } else if (difficulty == 2 && inputNumber > 500) {
        std::cout << "The number you entered was out of range!" << std::endl;
        std::cout << "---------------------" << std::endl;
        std::cout << "Please enter a number between 0 & " << highestNumber
                  << std::endl;
        std::cout << "$: ";

        std::cin >> inputNumber;

      } else if (difficulty == 3 && inputNumber > 1000) {
        std::cout << "The number you entered was out of range!" << std::endl;
        std::cout << "---------------------" << std::endl;
        std::cout << "Please enter a number between 0 & " << highestNumber
                  << std::endl;
        std::cout << "$: ";

        std::cin >> inputNumber;
      }

      if (inputNumber < targetNumber) {
        std::cout << "Higher!" << std::endl;
        std::cout << "$: ";
        std::cin >> inputNumber;
        guessCount++;
      } else {
        std::cout << "Lower!" << std::endl;
        std::cout << "$: ";
        std::cin >> inputNumber;
        guessCount++;
      }

      if (guessCount == 10) {
        std::cout << "Hint: Try using Binary Search" << std::endl;
      }
    }

    std::cout << "You Guessed Correctly! The number was " << targetNumber << "."
              << std::endl;
    std::cout << "It took you " << guessCount << " guesses." << std::endl;
    if (guessCount >= 20) {
      std::cout << "You're slower than python :( " << std::endl;
    } else if (guessCount > 25) {
      std::cout << "You should try again :| " << std::endl;
    }
    std::cout << "Want another round? (N/Y): ";

    std::cin >> approval;

    if (approval == 'n' || approval == 'N') {
      std::cout << "See you soon! :)" << std::endl;
    }

    rounds++;
  }

  return 0;
}

