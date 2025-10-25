#include <iostream>

int main() {
    float grade;
    std::cin >> grade;

    // Тези сравнения колко са коректни така?
    // Могат ли да се породят проблеми заради точност?
    if (grade >= 5.5) {
        std::cout << "Excellent";
    }
    else if (grade >= 4.5) {
        std::cout << "Very good";
    }
    else if (grade >= 3.5) {
        std::cout << "Good";
    }
    else if (grade >= 3.0) {
        std::cout << "Average";
    }
    else if (grade >= 2.0) {
        std::cout << "Weak";
    }
    else {
        std::cout << "Bad";
    }

    return 0;
}
