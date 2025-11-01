#include <iostream>

int main() {
    const unsigned int DIGITS = 8;
    const unsigned int WEIGHTS[DIGITS] = { 8, 6, 4, 2, 3, 5, 9, 7 };

    unsigned int serial_number;
    std::cin >> serial_number;

    unsigned int sum = 0;
    for (int i = DIGITS - 1; i >= 0; i--) {
        sum += (serial_number % 10) * WEIGHTS[i];
        serial_number /= 10;
    }

    unsigned int control_digit = 11 - sum % 11;

    if (control_digit == 10) control_digit = 0;
    else if (control_digit == 11) control_digit = 5;

    std::cout << control_digit << std::endl;

    return 0;
}
