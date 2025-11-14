#include <iostream>

const unsigned int SIZE_INPUT = 10, SIZE_OUTPUT = 5;

void subtractions(const double input[SIZE_INPUT], double output[SIZE_OUTPUT]) {
	for (unsigned int i = 0; i < SIZE_OUTPUT; i++)
		output[i] = input[i * 2 + 1] - input[i * 2];
}

int main() {
	double in[SIZE_INPUT], out[SIZE_OUTPUT];

	for (unsigned int i = 0; i < SIZE_INPUT; i++)
		std::cin >> in[i];

	subtractions(in, out);

	for (unsigned int i = 0; i < SIZE_OUTPUT; i++)
		std::cout << out[i] << ' ';
	std::cout << std::endl;

	return 0;
}
