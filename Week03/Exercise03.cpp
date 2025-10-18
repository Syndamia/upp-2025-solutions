#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    /* Алтернативно може да направите:
     * int a;
     * int b;
     * int c;
     * std::cin >> a;
     * std::cin >> b;
     * std::cin >> c;
     */

    std::cout << ((b - a) == (c - b));
    /* Друга формула, която също работи е:
     * (a + c) / 2 == b
     */
}
