#include <iostream>

int main() {
	unsigned int number;
	std::cin >> number;

	const unsigned int DIGITS = 10;
	unsigned char counts[DIGITS] = { 0 };

	unsigned int temp_number = number, number_length = 0;
	while (temp_number > 0) {
		counts[temp_number % 10]++;
		temp_number /= 10;
		number_length++;
	}

	unsigned int most_common = 0;
	for (unsigned int digit = 1; digit < DIGITS; digit++) {
		if (counts[digit] >= counts[most_common])
			most_common = digit;
	}

	unsigned int shifter = 1;
	for (unsigned int i = 0; i < number_length - 1; i++) {
		shifter *= 10;
	}

	while (shifter > 0) {
		if ((number / shifter) % 10 == most_common)
			temp_number *= 10;
		else
			temp_number = temp_number * 10 + (number / shifter) % 10;

		shifter /= 10;
	}

	std::cout << temp_number << std::endl;

	return 0;
}
