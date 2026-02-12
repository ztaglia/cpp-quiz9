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
    // for (int try = 1; try <= MAX_GUESSES; try++) {
    //     int guess = getGuess(try);
    std::cout << getGuess(1) << std::endl;
    return 0;
}
