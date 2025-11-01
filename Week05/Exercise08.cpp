#include <iostream>

int main() {
    const unsigned int SIZE = 10;

    /* Става по-елегантно ако използваме един масив */
    double row1[SIZE], row2[SIZE];
    for (int i = 0; i < SIZE; i++) {
        std::cin >> row1[i];
    }
    for (int i = 0; i < SIZE; i++) {
        std::cin >> row2[i];
    }

    char operation;
    std::cin >> operation;

    double result;
    for (int i = 0; i < SIZE; i++) {
        switch (operation) {
            case '+': result = row1[i] + row2[i]; break;
            case '-': result = row1[i] - row2[i]; break;
            case '*': result = row1[i] * row2[i]; break;
            case '/': result = row1[i] / row2[i]; break;
        }
        std::cout << result << ' ';
    }

    std::cout << std::endl;

    return 0;
}
