#include <iostream>

int main() {
    unsigned int number;
    std::cin >> number;

    unsigned int sum = 0;
    for (int div = 1; div < number; div++) {
        if (number % div == 0)
            sum += div;
    }

    if (sum == number)
        std::cout << "Perfect" << std::endl;
    else
        std::cout << "Not perfect" << std::endl;

    return 0;
}
