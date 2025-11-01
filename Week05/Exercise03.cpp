#include <iostream>

int main() {
    const unsigned int SIZE = 14;

    unsigned int numbers[SIZE];
    for (int i = 0; i < SIZE; i++) {
        std::cin >> numbers[i];
    }

    unsigned int largest = 0;
    for (int i = 0; i < SIZE; i++) {
        if (numbers[i] > largest)
            largest = numbers[i];
    }

    unsigned int second_largest = largest;
    for (int i = 0; i < SIZE; i++) {
        if (numbers[i] < largest && (numbers[i] > second_largest || second_largest == largest))
            second_largest = numbers[i];
    }

    std::cout << second_largest;

    return 0;
}
