#include <iostream>

int main() {
    unsigned int number;
    std::cin >> number;

    unsigned int reversed = 0;
    while (number > 0) {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }

    std::cout << reversed;

    return 0;
}
