#include <iostream>

int main() {
    unsigned int fib_index;
    std::cin >> fib_index;

    unsigned int prev = 0;
    unsigned int curr = 1;

    for (unsigned int index = 1; index <= fib_index; index++) {
        unsigned int old_curr = curr;
        curr += prev;
        prev = old_curr;
    }

    std::cout << prev;

    return 0;
}
