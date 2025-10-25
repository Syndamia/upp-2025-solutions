#include <iostream>

int main() {
    unsigned int n;
    std::cin >> n;

    float harmonic_number = 0.0;
    for (unsigned int i = 1; i <= n; i++) {
        harmonic_number += 1.0 / i;
    }

    std::cout << harmonic_number;

    return 0;
}
