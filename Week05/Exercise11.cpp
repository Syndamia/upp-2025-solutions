#include <iostream>

int main() {
    unsigned int lucas_i = 2, lucas_j = 1;
    unsigned int number;
    std::cin >> number;

    while (number > 0) {
        for (unsigned int i = 0; i < number; i++) {
            unsigned int old = lucas_j;
            lucas_j += lucas_i;
            lucas_i = old;
        }

        std::cout << lucas_i << ' ';
        std::cin >> number;
    }

    std::cout << lucas_i << std::endl;

    return 0;
}
