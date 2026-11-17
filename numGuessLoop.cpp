// Copyright (c) 2026 Bryson G All rights reserved.
// .
// Created by: Bryson G
// Date: 11,17,2026
// This program runs a guessing game where the user
// has to guess a number between 0 and 9
// but if you get it wrong it asks you to guess again until you get it right

#include <iostream>
#include <string>
#include <random>

int main() {
    // Declare variables
    std::string userNum;
    int userNumInt;
    int randomNum;

    // 1. Obtain a random seed from the hardware
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 9);
    randomNum = dist(gen);

    // Get the number from the user
    std::cout << "Guess a number between 0 and 9: ";
    std::cin >> userNum;
    while (userNumInt != randomNum) {
        // See if it is a valid number and convert it to an integer
        try {
            userNumInt = std::stoi(userNum);
            // See if it is a positive integer between 0 and 9
            if (userNumInt < 0 || userNumInt > 9) {
                std::cout << userNum << " is outside of the range 0 - 9 \n";
                std::cout << "Guess a number between 0 and 9: ";
                std::cin >> userNum;
            } else if (userNumInt != randomNum) {
                // If they get it wrong
                std::cout << "Sorry, that's not it. Try again \n";
                std::cout << "Guess a number between 0 and 9: ";
                std::cin >> userNum;
            } else if (userNumInt == randomNum) {
                // If they get it right
                std::cout << "You guessed it! The number was "
                << randomNum << "\n";
                break;
            }
        }
        catch (std::invalid_argument) {
            std::cout << userNum << " is not a valid number \n";
            std::cout << "Guess a number between 0 and 9: ";
            std::cin >> userNum;
        }
            }
}
