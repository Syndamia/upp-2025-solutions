#include <iostream>

int main() {
    char letter;
    std::cin >> letter;

    if ('a' <= letter && letter <= 'z') {
        std::cout << "Lowercase letter";
    }
    else if ('A' <= letter && letter <= 'Z') {
        std::cout << "Uppercase letter";
    }
    else if ('0' <= letter && letter <= '9') {
        std::cout << "Digit";
    }
    else {
        std::cout << "Other";
    }

    return 0;
}
