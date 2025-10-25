#include <iostream>

int main() {
    int number;
    std::cin >> number;

    for (int multiplier = 1; multiplier <= 10; multiplier++) {
        std::cout << multiplier << ' ' << (multiplier * number) << std::endl;
    }

    return 0;
}
