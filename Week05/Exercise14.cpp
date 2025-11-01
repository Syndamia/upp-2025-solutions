#include <iostream>

int main() {
    const unsigned int SIZE = 16;

    int numbers[SIZE];
    for (unsigned int i = 0; i < SIZE; i++) {
        std::cin >> numbers[i];
    }

    for (unsigned int i = 0; i < SIZE; i++) {
        if (numbers[i] % 2 == 0)
            std::cout << numbers[i] << ' ';
    }

    std::cout << std::endl;

    for (unsigned int i = 0; i < SIZE; i++) {
        if (numbers[i] % 2 != 0)
            std::cout << numbers[i] << ' ';
    }

    std::cout << std::endl;

    return 0;
}
