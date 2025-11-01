#include <iostream>

int main()
{
    double x;
    unsigned int n;
    std::cin >> x >> n;

    double sum = 0;

    for (unsigned int k = 0; k <= n; k++) {
        unsigned int l = 2 * k + 1;

        double to_power = 1;
        for (unsigned p = 1; p <= l; p++) {
            to_power *= x;
        }

        unsigned int fac = 1;
        for (unsigned i = 1; i <= l; i++) {
            fac *= i;
        }

        sum += (k % 2 ? -1.0 : 1.0) * to_power / fac;
    }

    std::cout << sum << std::endl;

    return 0;
}
