#include <iostream>
#include <cmath>

int main() {
    float a, b, c;
    std::cin >> a >> b >> c;

    float determinant = b * b - 4.0 * a * c;
    // Тези сравнения колко са коректни така?
    // Могат ли да се породят проблеми заради точност?
    if (determinant < 0.0) {
        std::cout << "No real roots";
    }
    else if (determinant == 0.0) {
        float x = -b / (2 * a);
        std::cout << x;
    }
    else {
        float x1 = (-b + sqrt(determinant)) / (2 * a);
        float x2 = (-b - sqrt(determinant)) / (2 * a);
        std::cout << x1 << ' ' << x2;
    }

    return 0;
}
