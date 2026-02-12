#undef NDEBUG

#include <iostream>
#include <cassert>
#include "Random.h"

const int MAX_GUESSES = 7;

int getGuess(int attempt) {
    std::cout << "Guess #" << attempt << ": ";
    int guess;
    std::cin >> guess;
    return guess;
}

int main() {
    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is." << std::endl;
    int secretNumber = Random::get(1, 100);
    assert(secretNumber >= 1 && secretNumber <= 100);
    assert(MAX_GUESSES == 7);
    for (int attempt = 1; attempt <= MAX_GUESSES; attempt++) {
        int guess = getGuess(attempt);
        if (guess > secretNumber) {
            std::cout << "Your guess is too high." << std::endl;
        } else if (guess < secretNumber) {
            std::cout << "Your guess is too low." << std::endl;
        } else {
            std::cout << "Correct! You win!" << std::endl;
        }
    std::cout << "Sorry, you lose. The correct number was " << secretNumber << "." << std::endl;
    while (true) {
        std::cout << "Would you like to play again? (y/n)? ";
        char playAgain;
        std::cin >> playAgain;
        if (playAgain == 'y') {
            return main();
        } else if (playAgain == 'n') {
            std::cout << "Thanks for playing!" << std::endl;
        }
    }
    return 0;
}
