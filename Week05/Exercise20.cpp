#include <iostream>

int main() {
    unsigned int number;
    std::cin >> number;

    unsigned int check_digit = number % 10;
    number /= 10;

    unsigned int sum = 0, digit = 0;
    for (unsigned int multiplier = 2; number != 0; multiplier = multiplier % 2 + 1, number /= 10) {
        digit = (number % 10) * multiplier;
        if (digit > 9) digit -= 9;
        sum += digit;
    }

    if ((10 - (sum % 10)) % 10 == check_digit)
        std::cout << "Valid" << std::endl;
    else
        std::cout << "Invalid" << std::endl;

    return 0;
}
