#include <iostream>

int main() {
    unsigned int factorial_max, power;
    std::cin >> factorial_max >> power;

    unsigned int factorial = 1;
    for (unsigned int i = 1; i <= factorial_max; i++) {
        factorial *= i;
    }

    unsigned int to_power = 1;
    for (unsigned int i = 1; i <= power; i++) {
        to_power *= factorial;
    }

    std::cout << to_power;

    return 0;
}
