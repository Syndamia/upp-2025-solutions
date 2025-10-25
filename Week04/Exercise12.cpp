#include <iostream>

int main() {
    char operation;
    std::cin >> operation;

    while (operation != '.') {
        int a, b;
        std::cin >> a >> b;

        int result = 0;
        switch (operation) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': result = a / b; break;
        }
        std::cout << result << std::endl;

        std::cin >> operation;
    }

    return 0;
}
