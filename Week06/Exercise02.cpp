#include <iostream>

int main() {
	const unsigned int SIZE = 8;

	unsigned int nums[SIZE];
	for (unsigned int i = 0; i < SIZE; i++)
		std::cin >> nums[i];

	unsigned int divisor = nums[0];
	while (divisor > 1) {
		bool is_gcd = true;

		for (unsigned int i = 0; i < SIZE && is_gcd; i++)
			if (nums[i] % divisor != 0)
				is_gcd = false;

		if (is_gcd) break;
		divisor--;
	}

	std::cout << divisor << std::endl;

	return 0;
}
