#include <iostream>

int main() {
    unsigned int S, n;
    std::cin >> S >> n;

    double a = S, power_10 = 1;
    while (a > 100.0) {
        a /= 100.0;
        power_10 *= 10.0;
    }

    double x_i = (10.0 - 190.0 / (a + 20.0)) * power_10;
    double x_n = (x_i + S / x_i) / 2.0;
    for (unsigned int i = 1; i < n; i++) {
        double old_x = x_n;
        x_n = (x_i + S / x_i) / 2.0;
        x_i = x_n;
    }

    std::cout << x_i;

    return 0;
}
