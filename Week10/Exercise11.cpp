#include <iostream>

int main() {
	unsigned int n;
	std::cin >> n;

	double* coeffs = new double[n + 1];
	for (unsigned int i = 0; i < n + 1; i++)
		std::cin >> coeffs[i];

	double potentialRoot;
	std::cin >> potentialRoot;

	double sum = 0.0, toPower = 1.0;
	for (unsigned int i = n + 1; i > 0; i--) {
		sum += coeffs[i-1] * toPower;
		toPower *= potentialRoot;
	}

	const double ZERO_BORDER = 0.00001;

	if (-ZERO_BORDER < sum && sum < ZERO_BORDER) {
		std::cout << "Is a root" << std::endl;
	}
	else {
		std::cout << "Not a root" << std::endl;
	}

	delete[] coeffs;

	return 0;
}
