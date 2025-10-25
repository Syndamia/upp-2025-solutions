#include <iostream>

int main() {
    unsigned int number;
    std::cin >> number;

    unsigned int factorial = 1;
    for (unsigned int current = 2; current <= number; current++) {
        factorial *= current;
    }

    std::cout << factorial;

    return 0;
}
