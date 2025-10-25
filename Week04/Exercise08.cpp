#include <iostream>

int main() {
    unsigned int a, x;
    std::cin >> a >> x;

    unsigned int product = 1;
    for (unsigned int power = 1; power <= x; power++) {
        product *= a;
    }

    std::cout << product;

    return 0;
}
