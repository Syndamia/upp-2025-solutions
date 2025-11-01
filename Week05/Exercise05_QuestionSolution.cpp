#include <iostream>

/* Отговорът е не, не са нужни масиви. */

int main() {
    const unsigned int SIZE = 18;

    unsigned int zero_count = 0;
    int number;

    for (int i = 0; i < SIZE; i++) {
        std::cin >> number;

        if (number == 0)
            zero_count++;
        else
            std::cout << number << ' ';
    }

    for (int i = 0; i < zero_count; i++) {
        std::cout << 0 << ' ';
    }

    return 0;
}
