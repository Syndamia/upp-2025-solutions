#include <iostream>

// Припомняме, че "unsigned" е същото като "unsigned int"
unsigned sumElems(int* arr, unsigned size) {
	int sum = 0;
	for (unsigned int i = 0; i < size; i++)
		sum += arr[i];
	return sum;
}

int main() {
	const unsigned int SIZE = 11;
	int input[SIZE];
	for (unsigned int i = 0; i < SIZE; i++)
		std::cin >> input[i];

	for (unsigned int i = 0; i <= SIZE - 3; i++) {
		if (sumElems(input + i, 3) == 0) {
			std::cout << input[i] << ' ' << input[i + 1] << ' ' << input[i + 2] << std::endl;
			return 0;
		}
	}

	return 0;
}
