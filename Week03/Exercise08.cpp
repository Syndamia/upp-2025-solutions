#include <iostream>

int main() {
    double a, b, c, d, x;
    std::cin >> a >> b >> c >> d >> x;

    std::cout << (a * x * x * x + b * x * x + c * x + d == 0);

    return 0;
}
