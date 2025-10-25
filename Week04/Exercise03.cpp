#include <iostream>

int main() {
    unsigned short day;
    std::cin >> day;

    switch ((day - 1) % 7) {
        case 0: std::cout << "Monday"; break;
        case 1: std::cout << "Tuesday"; break;
        case 2: std::cout << "Wednesday"; break;
        case 3: std::cout << "Thursday"; break;
        case 4: std::cout << "Friday"; break;
        case 5: std::cout << "Saturday"; break;
        case 6: std::cout << "Sunday"; break;
    }

    return 0;
}
