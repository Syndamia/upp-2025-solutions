#include <iostream>

int main() {
    unsigned int number;
    std::cin >> number;

    unsigned int number_length, number_copy = number;

    for (number_length = 0; number_copy != 0; number_length++) {
        number_copy /= 10;
    }

    unsigned int sum = 0;
    number_copy = number;

    while (number_copy != 0) {
        unsigned int to_power = 1, digit = number_copy % 10;

        for (unsigned int i = 0; i < number_length; i++) {
            to_power *= digit;
        }

        sum += to_power;
        number_copy /= 10;
    }

    if (number == sum)
        std::cout << "Narcissistic" << std::endl;
    else
        std::cout << "Not narcissistic" << std::endl;

    return 0;
}
