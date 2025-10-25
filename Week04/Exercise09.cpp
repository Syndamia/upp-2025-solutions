#include <iostream>

int main() {
    unsigned int max_number;
    std::cin >> max_number;

    unsigned int even_sum = 0;
    unsigned int odd_sum = 0;

    for (unsigned int current_number = 1; current_number <= max_number; current_number++) {
        if (current_number % 2 == 0) {
            even_sum += current_number;
        }
        else {
            odd_sum += current_number;
        }
    }

    std::cout << even_sum << ' ' << odd_sum;

    return 0;
}
