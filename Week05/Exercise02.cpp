#include <iostream>

int main() {
    const unsigned int SIZE = 7;

    char letters[SIZE];
    for (int i = 0; i < SIZE; i++) {
        std::cin >> letters[i];
    }

    for (int i = 0; i < SIZE; i++) {
        std::cout << letters[(i + 4) % SIZE] << ' ';
    }

    return 0;
}
