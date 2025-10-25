#include <iostream>

int main() {
    float goal, range;
    std::cin >> goal >> range;

    float sum = 0, element;
    std::cin >> element;

    sum += element;
    float percent_difference = (sum > goal ? sum - goal : goal - sum) / ((goal + sum) / 2.0) * 100.0;

    while (100.0 - percent_difference < range) {
        std::cin >> element;

        sum += element;
        percent_difference = (sum > goal ? sum - goal : goal - sum) / ((goal + sum) / 2.0) * 100.0;
    }

    std::cout << sum;

    return 0;
}
