#include <iostream>

int main() {
    int product = 1;

    int number;
    std::cin >> number;
    while (number != 0) {
        product *= number;
        std::cin >> number;
    }

    std::cout << product;

    return 0;
}
