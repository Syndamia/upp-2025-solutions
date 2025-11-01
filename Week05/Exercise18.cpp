#include <iostream>

int main() {
    const unsigned int SIZE = 7;

    int numbers[SIZE];
    for (unsigned int i = 0; i < SIZE; i++) {
        std::cin >> numbers[i];
    }

    int left_sum = 0, right_sum = 0;
    for (unsigned int i = 1; i < SIZE; i++) {
        right_sum += numbers[i];
    }

    unsigned int balance_index = 0;
    while (balance_index < SIZE && left_sum != right_sum) {
        left_sum += numbers[balance_index];
        balance_index++;
        right_sum -= numbers[balance_index];
    }

    if (balance_index == SIZE)
        std::cout << "No such index" << std::endl;
    else
        std::cout << balance_index << std::endl;

    return 0;
}
