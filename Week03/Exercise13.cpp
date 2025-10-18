#include <iostream>

int main() {
    const double PI = 3.14159;

    double alpha, beta;
    std::cin >> alpha >> beta;

    double x = alpha + beta;
    double sinx = (16.0 * x * (PI - x)) / (5 * PI * PI - 4 * x * (PI - x));
    x += PI / 2;
    double cosx = (16.0 * x * (PI - x)) / (5 * PI * PI - 4 * x * (PI - x));
    std::cout << (sinx / cosx);

    return 0;
}
