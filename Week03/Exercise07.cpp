#include <iostream>

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    float average = (float)(a + b + c + d) / 4.0;
    int sum       = a + b + c + d;
    float inv_sum = 1.0 / (float)a + 1.0 / (float)b + 1.0 / (float)c + 1.0 / (float)d;
    int product   = a * b * c * d;
    std::cout << average << ' ' << sum << ' ' << inv_sum << ' ' << product;
    /* В горните сметки можем да пропуснем конвертиранията към float.
     * Защо?
     * И какво можем да променим, така че сметките да се нуждаят от конвертиране?
     */

    return 0;
}
