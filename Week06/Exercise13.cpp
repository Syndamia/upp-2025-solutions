#include <iostream>

int main() {
	unsigned int number;
	std::cin >> number;

	for (unsigned int divisor = 1; divisor <= number; divisor++) {
		if (number % divisor == 0)
			std::cout << divisor << ' ';
	}
	std::cout << std::endl;

	return 0;
}
