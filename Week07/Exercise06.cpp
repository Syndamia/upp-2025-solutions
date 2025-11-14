#include <iostream>

// Припомняме, че "unsigned" е същото като "unsigned int"
void minmaxElems(int* arr, unsigned size, int* min, int* max) {
	*min = arr[0];
	*max = arr[0];
	for (unsigned int i = 1; i < size; i++) {
		if (arr[i] > *max) *max = arr[i];
		if (arr[i] < *min) *min = arr[i];
	}
}

int main() {
	const unsigned int SIZE1 = 10, SIZE2 = 8;
	int series1[SIZE1], series2[SIZE2];

	for (unsigned int i = 0; i < SIZE1; i++)
		std::cin >> series1[i];
	for (unsigned int i = 0; i < SIZE2; i++)
		std::cin >> series2[i];

	int min, max;
	minmaxElems(series1, SIZE1, &min, &max);
	std::cout << max << ' ' << min << std::endl;

	minmaxElems(series2, SIZE2, &min, &max);
	std::cout << max << ' ' << min << std::endl;

	return 0;
}
