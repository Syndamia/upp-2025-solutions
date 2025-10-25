#include <iostream>

int main() {
    float x, y;
    std::cin >> x >> y;

    if (x < y) {
        std::cout << x << ' ' << y;
    }
    else {
        std::cout << y << ' ' << x;
    }

    return 0;
}
