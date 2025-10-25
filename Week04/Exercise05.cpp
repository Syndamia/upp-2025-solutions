#include <iostream>

int main() {
    char operation;
    std::cin >> operation;

    if (operation == '_') {
        float number;
        std::cin >> number;
        std::cout << (int)number;
    }
    else if (operation == '+') {
        float a, b;
        std::cin >> a >> b;
        std::cout << (a + b);
    }
    else if (operation == '*') {
        float a, b;
        std::cin >> a >> b;
        std::cout << (a * b);
    }
    else if (operation == 'x') {
        float a, b, c;
        std::cin >> a >> b >> c;
        std::cout << (a * b * c);
    }
    else if (operation == '.') {
        float a, b, c, d;
        std::cin >> a >> b >> c >> d;
        std::cout << (a * b * c * d);
    }

    return 0;
}
