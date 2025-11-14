#include <iostream>

void pow2(unsigned long long* arr, unsigned int size) {
	for (unsigned int i = 0; i < size; i++)
		arr[i] *= arr[i];
}

void mult3(unsigned long long* arr, unsigned int size) {
	for (unsigned int i = 0; i < size; i++)
		arr[i] *= 3;
}

bool contains(unsigned long long* arr, unsigned int size, unsigned long long element) {
	for (unsigned int i = 0; i < size; i++)
		if (arr[i] == element)
			return true;
	return false;
}

int main() {
	const unsigned long long SIZE = 5;

	unsigned long long input[SIZE], goal;
	for (unsigned int i = 0; i < SIZE; i++)
		std::cin >> input[i];
	std::cin >> goal;

	for (unsigned long long i = 0; !contains(input, SIZE, goal); i++) {
		if (i % 2 == 0)
			pow2(input, SIZE);
		else
			mult3(input, SIZE);
	}

	for (unsigned long long i = 0; i < SIZE; i++)
		std::cout << input[i] << ' ';
	std::cout << std::endl;

	return 0;
}
