#include <iostream>

int main() {
    float numbers[10];
    for (int i = 0; i < 10; i++) {
        std::cin >> numbers[i];
    }

    for (int i = 9; i >= 0; i--) {
        std::cout << numbers[i] << ' ';
    }

    return 0;
}
