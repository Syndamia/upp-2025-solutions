#include <iostream>

int main() {
	unsigned int number;
	std::cin >> number;

	while (number != 4 && number != 1) {
		unsigned int temp_number = 0;
		while (number > 0) {
			temp_number += (number % 10) * (number % 10);
			number /= 10;
		}
		number = temp_number;
	}

	if (number == 1)
		std::cout << "Happy" << std::endl;
	else
		std::cout << "Not happy" << std::endl;

	return 0;
}
