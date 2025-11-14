#include <iostream>

void rotate(const unsigned int* input, unsigned int size, unsigned int rotation, unsigned int* output) {
	rotation %= size;

	for (unsigned int i = 0; i < size; i++)
		output[(i + rotation) % size] = input[i];
}

// Никой не е забранил да правим допълнителни функции.
// ВНИМАНИЕ: входния размер ТРЯБВА да бъде константа!
void rotateUserInput(const unsigned int SIZE) {
	unsigned int series[SIZE], rotation;

	for (unsigned int i = 0; i < SIZE; i++)
		std::cin >> series[i];
	std::cin >> rotation;

	unsigned int result[SIZE];
	rotate(series, SIZE, rotation, result);

	for (unsigned int i = 0; i < SIZE; i++)
		std::cout << result[i] << ' ';
	std::cout << std::endl;
}

int main() {
	rotateUserInput(6);
	rotateUserInput(7);

	return 0;
}
