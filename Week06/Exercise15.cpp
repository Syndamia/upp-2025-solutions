#include <iostream>

int main() {
	const unsigned int SIZE = 8;
	unsigned int numbers[SIZE];

	for (unsigned int i = 0; i < SIZE; i++)
		std::cin >> numbers[i];

	for (int i = 1; i < SIZE; i++) {
		for (unsigned int lcm = numbers[i]; true; lcm++) {
			if (lcm % numbers[i - 1] == 0 && lcm % numbers[i] == 0) {
				std::cout << lcm << ' ';
				break;
			}
		}
	}
	std::cout << std::endl;

	return 0;
}
