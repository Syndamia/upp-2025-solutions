#include <iostream>

int main() {
    const unsigned int NUMBER = 1337;

    unsigned int guess;
    std::cin >> guess;

    while (guess != NUMBER) {
        if (guess < NUMBER) {
            std::cout << "Higher" << std::endl;
        }
        else {
            std::cout << "Lower" << std::endl;
        }
        std::cin >> guess;
    }
    std::cout << "You guessed it!";

    return 0;
}
