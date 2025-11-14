#include <iostream>

unsigned int countSameElementsOnSameIndecies(int* arr1, unsigned int size1, int* arr2, unsigned int size2) {
	unsigned int count = 0;
	unsigned int size = size1 < size2 ? size1 : size2;

	for (unsigned int i = 0; i < size; i++)
		if (arr1[i] == arr2[i])
			count++;

	return count;
}

int main() {
	const unsigned int SIZE1 = 10, SIZE2 = 15;
	int series1[SIZE1], series2[SIZE2];

	for (unsigned int i = 0; i < SIZE1; i++)
		std::cin >> series1[i];
	for (unsigned int i = 0; i < SIZE2; i++)
		std::cin >> series2[i];

	std::cout << countSameElementsOnSameIndecies(series1, SIZE1, series2, SIZE2) << std::endl;

	return 0;
}
