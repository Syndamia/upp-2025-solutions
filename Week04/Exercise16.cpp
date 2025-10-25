#include <iostream>

int main() {
    float alpha, beta, gamma;
    std::cin >> alpha >> beta >> gamma;

    if (alpha > 0.0 && beta > 0.0 && gamma > 0.0 && (alpha + beta + gamma) == 180.0) {
        if (alpha == beta && beta == gamma) {
            std::cout << "Equilateral";
        }
        else if ((alpha == beta && beta != gamma) || (alpha == gamma && gamma != beta) || (beta == gamma && gamma != alpha)) {
            std::cout << "Isosceles";
        }
        else if (alpha < 90.0 && beta < 90.0 && gamma < 90.0) {
            std::cout << "Acute";
        }
        else if (alpha > 90.0 || beta > 90.0 || gamma > 90.0) {
            std::cout << "Obtuse";
        }
        else {
            std::cout << "Right";
        }
        std::cout << " triangle";
    }

    return 0;
}
