#include <iostream>

void incArr(int* arr, unsigned int size) {
	for (unsigned int i = 0; i < size; i++)
		arr[i]++;
}

int main() {
	const unsigned int SIZE1 = 10, SIZE2 = 9;
	int series1[SIZE1], series2[SIZE2];

	for (unsigned int i = 0; i < SIZE1; i++)
		std::cin >> series1[i];
	for (unsigned int i = 0; i < SIZE2; i++)
		std::cin >> series2[i];

	incArr(series1, SIZE1);
	incArr(series2, SIZE2);

	for (unsigned int i = 0; i < SIZE1; i++)
		std::cout << series1[i] << ' ';
	std::cout << std::endl;

	for (unsigned int i = 0; i < SIZE2; i++)
		std::cout << series2[i] << ' ';
	std::cout << std::endl;

	return 0;
}
