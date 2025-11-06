#include <iostream>

int main() {
	unsigned int number;
	std::cin >> number;

	unsigned int temp_number = number, digit_sum = 0, digit_prod = 1;
	while (temp_number > 0) {
		digit_sum += temp_number % 10;
		digit_prod *= temp_number % 10;
		temp_number /= 10;
	}

	if (number == digit_sum * digit_prod)
		std::cout << "Sum-product number" << std::endl;
	else
		std::cout << "Not a sum-product number" << std::endl;

	return 0;
}
