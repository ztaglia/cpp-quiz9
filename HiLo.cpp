#undef NDEBUG

#include <iostream>
#include <cassert>
#include <limits>
#include "Random.h"

// Update your previous solution to handle invalid guesses (e.g. ‘x’), 
// out of bounds guesses (e.g. 0 or 101), 
// or valid guesses that have extraneous characters (e.g. 43x). 
// Also handle the user entering extra characters 
// when the game asks them whether they want to play again.

const int MAX_GUESSES = 7;

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getGuess(int attempt) {
    std::cout << "Guess #" << attempt << ": ";
    int guess;
    std::cin >> guess;
    if (!std::cin) {
        std::cin.clear();
        ignoreLine();
        std::cout << "Invalid input." << std::endl;
        return getGuess(attempt);
    } 
    if (guess < 1 || guess > 100) {
        std::cout << "Invalid: Out of bounds." << std::endl;
        return getGuess(attempt);
    }
    std::cin.clear();
    ignoreLine();
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
            return 0;
        }
    }
    return 0;
}
