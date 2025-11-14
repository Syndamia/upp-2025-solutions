#include <iostream>

double topower(double x, unsigned int a) {
	double result = 1.0;
	for (unsigned int i = 1; i <= a; i++)
		result *= x;
	return result;
}

int main() {
	const unsigned int SIZE = 11;
	double coeffs[SIZE], root;

	for (unsigned int i = 0; i < SIZE; i++)
		std::cin >> coeffs[i];
	std::cin >> root;

	double sum = 0.0;
	for (unsigned int i = 0; i < SIZE; i++)
		sum += coeffs[i] * topower(root, 10 - i);

	const double ZERO_BORDER = 0.0001;
	if (-ZERO_BORDER < sum && sum < ZERO_BORDER)
		std::cout << "Is a root" << std::endl;
	else
		std::cout << "Not a root" << std::endl;

	return 0;
}
