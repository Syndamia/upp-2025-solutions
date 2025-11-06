#include <iostream>

int main() {
	const unsigned int SIZE = 6;
	double numbers[SIZE];
	for (int i = 0; i < SIZE; i++)
		std::cin >> numbers[i];

	double prefix_sums[SIZE] = { 0 };
	double rolling_sum = 0;
	for (int i = 0; i < SIZE; i++) {
		rolling_sum += numbers[i];
		prefix_sums[i] = rolling_sum;
	}

	for (int i = 0; i < SIZE; i++)
		std::cout << prefix_sums[i] << ' ';
	std::cout << std::endl;

	return 0;
}
