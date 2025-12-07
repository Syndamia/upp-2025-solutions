#include <iostream>

int main() {
	unsigned int n;
	std::cin >> n;

	double* numbers = new double[n];
	for (unsigned int i = 0; i < n; i++)
		std::cin >> numbers[i];

	for (unsigned int i = n; i > 0; i--)
		std::cout << numbers[i-1] << ' ';
	std::cout << std::endl;

	delete[] numbers;

	return 0;
}
