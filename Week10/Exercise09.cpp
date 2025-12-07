#include <iostream>

unsigned int* inputArray(unsigned int size) {
	unsigned int* arr = new unsigned int[size];
	for (unsigned int i = 0; i < size; i++)
		std::cin >> arr[i];
	return arr;
}

void resizeArrayUINTPP(unsigned int**& arr, unsigned int size) {
	unsigned int** newArr = new unsigned int*[size * 2];
	for (unsigned int i = 0; i < size; i++)
		newArr[i] = arr[i];

	delete[] arr;
	arr = newArr;
}

void resizeArrayUINTP(unsigned int*& arr, unsigned int size) {
	unsigned int* newArr = new unsigned int[size * 2];
	for (unsigned int i = 0; i < size; i++)
		newArr[i] = arr[i];

	delete[] arr;
	arr = newArr;
}

int main() {
	unsigned int jaggedCount = 0, jaggedSize = 4, mostColumns = 0;
	unsigned int** jagged = new unsigned int*[jaggedSize], *rowSizes = new unsigned int[jaggedSize];

	unsigned int size;
	std::cin >> size;
	while (size > 0) {
		rowSizes[jaggedCount] = size;
		jagged[jaggedCount++] = inputArray(size);

		if (size > mostColumns)
			mostColumns = size;

		if (jaggedCount >= jaggedSize) {
			resizeArrayUINTP(rowSizes, jaggedSize);
			resizeArrayUINTPP(jagged, jaggedSize);
			jaggedSize *= 2;
		}

		std::cin >> size;
	}

	for (unsigned int col = mostColumns; col > 0; col--) {
		for (unsigned int row = 0; row < jaggedCount; row++)
			if (col - 1 < rowSizes[row])
				std::cout << jagged[row][col - 1] << ' ';
		std::cout << std::endl;
	}

	for (unsigned int i = 0; i < jaggedSize; i++)
		delete[] jagged[i];
	delete[] jagged;
	delete[] rowSizes;

	return 0;
}
