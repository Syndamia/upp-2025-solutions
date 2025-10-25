#include <iostream>

int main() {
    const float PI = 3.14159;

    unsigned short shape;
    std::cin >> shape;

    if (shape == 1) {
        float r;
        std::cin >> r;
        std::cout << (2.0 * PI * r);
    }
    else if (shape == 2) {
        float a, b;
        std::cin >> a >> b;
        std::cout << (2.0 * a + 2.0 * b);
    }
    else if (shape == 3) {
        float a, b, c;
        std::cin >> a >> b >> c;
        std::cout << (a + b + c);
    }

    return 0;
}
