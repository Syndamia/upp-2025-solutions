#include <iostream>

int main() {
    const unsigned int SIZE = 20;

    unsigned short indecies[SIZE];
    bool visited[SIZE];
    for (unsigned int i = 0; i < SIZE; i++) {
        std::cin >> indecies[i];
        visited[i] = false;
    }

    unsigned int current_index = 0, jumps = 0;
    while (current_index != SIZE - 1 && !visited[current_index]) {
        visited[current_index] = true;
        current_index = indecies[current_index];
        jumps++;
    }

    if (current_index != SIZE - 1)
        std::cout << "Infinity" << std::endl;
    else
        std::cout << jumps << std::endl;

    return 0;
}
