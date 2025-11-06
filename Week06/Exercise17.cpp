#include <iostream>

int main() {
	unsigned int a, b;
	std::cin >> a >> b;

	unsigned int c = b / a, gcd = c;
	// Към какво може да се опрости долния булев израз?
	while (!(a % gcd == 0 && c % gcd == 0)) {
		gcd--;
	}

	if (b % a == 0 && gcd == 1)
		std::cout << "Unitary divisor" << std::endl;
	else
		std::cout << "Not a unitary divisor" << std::endl;

	return 0;
}
