#include <iostream>

int main() {
    char current, goal;
    std::cin >> current >> goal;

    std::cout << ((goal - current + 26) % 26);

    return 0;
}
