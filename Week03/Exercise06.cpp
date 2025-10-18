#include <iostream>

int main() {
    bool p, q;
    std::cin >> p >> q;

    std::cout << ((!p || q) && (!q || p));
    /* Ако се вгледате в таблицата на истинност, тогава
     * може да се досетите, че има по-прост израз:
     * p == q
     */

    return 0;
}
