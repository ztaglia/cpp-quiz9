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
const int MIN_NUM = 1;
const int MAX_NUM = 100;

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getGuess(int attempt) {
    while (true) {
        std::cout << "Guess #" << attempt << ": ";
        int guess;
        std::cin >> guess;
        if (!std::cin) {
            std::cin.clear();
            ignoreLine();
            std::cout << "Invalid input." << std::endl;
            continue;
        } else if (guess < MIN_NUM || guess > MAX_NUM) {
            std::cout << "Invalid: Out of bounds." << std::endl;
            continue;
        }
        std::cin.clear();
        ignoreLine();
        return guess;
    }
}

bool playAgain() {
    while (true) {
        std::cout << "Would you like to play again? (y/n)? ";
        char playAgain;
        std::cin >> playAgain;
        switch(playAgain) {
            case 'y':
                return true;
            case 'n':
                return false;
            default:
                std::cin.clear();
                ignoreLine();
                std::cout << "Invalid input." << std::endl;
        }
    }
}

bool hiLo() {
    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is." << std::endl;
    int secretNumber = Random::get(MIN_NUM, MAX_NUM);
    assert(secretNumber >= MIN_NUM && secretNumber <= MAX_NUM);
    assert(MAX_GUESSES == 7);
    for (int attempt = 1; attempt <= MAX_GUESSES; attempt++) {
        int guess = getGuess(attempt);
        if (guess > secretNumber) {
            std::cout << "Your guess is too high." << std::endl;
        } else if (guess < secretNumber) {
            std::cout << "Your guess is too low." << std::endl;
        } else {
            std::cout << "Correct! You win!" << std::endl;
            return true;
        }
    }
    std::cout << "Sorry, you lose. The correct number was " << secretNumber << "." << std::endl;
    return false;
}

int main() {
    do {
        hiLo();
    } while (playAgain());

    std::cout << "Thanks for playing!" << std::endl;

    return 0;
}
