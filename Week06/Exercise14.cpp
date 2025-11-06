#include <iostream>

int main() {
	unsigned int base, tetration;
	std::cin >> base >> tetration;

	unsigned long long product = 1, pow = base;
	for (unsigned int tetr = 0; tetr < tetration - 1; tetr++) {
		for (unsigned int i = 0; i < pow; i++) {
			product *= base;
		}
		pow = product;
		product = 1;
	}

	std::cout << pow << std::endl;

	return 0;
}
