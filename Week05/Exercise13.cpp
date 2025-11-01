#include <iostream>

int main() {
    const unsigned int SIZE = 8;

    int numbers[SIZE];
    for (unsigned int i = 0; i < SIZE; i++) {
        std::cin >> numbers[i];
    }

    int search;
    std::cin >> search;

    unsigned int occurrences = 0;
    for (unsigned int i = 0; i < SIZE; i++) {
        if (numbers[i] == search)
            occurrences++;
    }

    std::cout << occurrences << std::endl;

    return 0;
}
