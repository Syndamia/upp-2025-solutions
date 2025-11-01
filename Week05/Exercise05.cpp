#include <iostream>

int main() {
    const unsigned int SIZE = 18;

    int numbers[SIZE];
    for (int i = 0; i < SIZE; i++) {
        std::cin >> numbers[i];
    }

    for (int i = 0; i < SIZE; i++) {
        if (numbers[i] == 0)
            std::cout << numbers[i] << ' ';
    }

    for (int i = 0; i < SIZE; i++) {
        if (numbers[i] != 0)
            std::cout << numbers[i] << ' ';
    }

    return 0;
}
