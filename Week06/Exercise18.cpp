#include <iostream>

int main() {
	const unsigned int SIZE = 10;
	float numbers[SIZE];

	for (unsigned int i = 0; i < SIZE; i++) {
		std::cin >> numbers[i];
	}

	double max_sum = numbers[0];
	for (unsigned int length = 1; length <= SIZE; length++) {
		for (unsigned int start = 0; start <= SIZE - length; start++) {
			double sum = 0.0;

			for (unsigned int i = start; i < length; i++) {
				sum += numbers[i];
			}

			if (sum > max_sum)
				max_sum = sum;
		}
	}

	std::cout << max_sum << std::endl;

	return 0;
}
