#include <iostream>

int main() {
    const unsigned int SIZE = 12;

    double numbers[SIZE];
    for (unsigned int i = 0; i < SIZE; i++) {
        std::cin >> numbers[i];
    }

    for (unsigned int i = 0; i < SIZE / 2; i++) {
        std::cout << numbers[i] << ' ' << numbers[SIZE - 1 - i] << std::endl;
    }

    return 0;
}
