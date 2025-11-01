#include <iostream>

int main() {
    unsigned int n;
    std::cin >> n;

    unsigned long f1 = 1, f2 = 1, f3 = 1;
    for (unsigned long i = 1; i <= 2 * n; i++) {
        f1 *= i;
        if (i <= n + 1)
            f2 *= i;
        if (i <= n)
            f3 *= i;
    }

    unsigned long catalan = f1 / (f2 * f3);

    std::cout << catalan << std::endl;

    return 0;
}
