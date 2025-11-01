#include <iostream>

int main() {
    const unsigned int SIZE = 15;

    int current_number, prev_number;
    unsigned int size_current_series = 1, size_longest_series = 0;

    std::cin >> prev_number;
    for (int i = 1; i < SIZE; i++) {
        std::cin >> current_number;

        if (prev_number > current_number)
            size_current_series = 0;

        size_current_series++;

        if (size_current_series > size_longest_series)
            size_longest_series = size_current_series;

        prev_number = current_number;
    }

    std::cout << size_longest_series;

    return 0;
}
