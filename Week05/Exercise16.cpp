#include <iostream>

int main() {
    const unsigned int SIZE = 5;

    int row1[SIZE], row2[SIZE];
    for (int i = 0; i < SIZE; i++) {
        std::cin >> row1[i];
    }
    for (int i = 0; i < SIZE; i++) {
        std::cin >> row2[i];
    }

    for (int i = 0; i < SIZE * 2; i++) {
        if (i % 2 == 0)
            std::cout << row1[i / 2] << ' ';
        else
            std::cout << row2[(i - 1) / 2] << ' ';
    }

    std::cout << std::endl;

    return 0;
}
