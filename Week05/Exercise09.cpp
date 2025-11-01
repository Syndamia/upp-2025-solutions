#include <iostream>

int main()
{
    double z;
    unsigned int n;
    std::cin >> z >> n;

    double base = z - 1;
    double sum = 0;

    for (unsigned int i = 1; i <= n; i++) {
        double to_power = 1;

        for (unsigned j = 1; j <= i; j++) {
            to_power *= base;
        }

        sum += ((i + 1) % 2 ? -1.0 : 1.0) * to_power / i;
    }

    std::cout << sum << std::endl;

    return 0;
}
