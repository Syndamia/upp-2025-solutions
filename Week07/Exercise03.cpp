#include <iostream>

const unsigned int SIZE = 15;

double average(int numbers[SIZE]) {
	double sum = 0;

	for (unsigned int i = 0; i < SIZE; i++)
		sum += numbers[i];

	return sum / SIZE;
}

int main() {
	int input[SIZE];
	for (unsigned int i = 0; i < SIZE; i++)
		std::cin >> input[i];

	std::cout << average(input) << std::endl;

	return 0;
}
