#include <iostream>

int main() {
    unsigned int num;
    std::cin >> num;

    unsigned int divisor;
    for (divisor = 2; divisor <= num; divisor++) {
        if (num % divisor == 0) {
            break;
        }
    }
    /* Това горе е най-простия възможен алгоритъм за търсене на просто число.
     * Може да се направи по-бърз, като примерно ограничим divisor да бъде
     * най-много num / 2 или пък даже sqrt(num) и като пропускаме числа.
     * За любознателните:
     * https://en.wikipedia.org/w/index.php?title=Primality_test&oldid=1220893086#Simple_methods
     */

    if (divisor != num) {
        std::cout << "Not prime " << divisor;
    }
    else {
        std::cout << "Prime";
    }

    return 0;
}
