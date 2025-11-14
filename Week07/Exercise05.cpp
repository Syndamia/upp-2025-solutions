#include <iostream>

// Добра практика е, когато приемаме указатели, от които само четем стойности,
// да ги направим константни. В близкото бъдеще това ще стане строго ограничение.
double maxElem(const double* numbers, unsigned int size) {
	double max = *numbers;    // еквивалентно на numbers[0], защото numbers[0] се свежда до *(numbers + 0)

	for (unsigned int i = 0; i < size; i++)
		if (numbers[i] > max)    // numbers[i] е еквивалентно на *(numbers + i)
			max = numbers[i];

	return max;
}

int main() {
	const unsigned int SIZE1 = 5, SIZE2 = 7;
	double series1[SIZE1], series2[SIZE2];

	for (unsigned int i = 0; i < SIZE1; i++)
		std::cin >> series1[i];
	for (unsigned int i = 0; i < SIZE2; i++)
		std::cin >> series2[i];

	std::cout << maxElem(series1, SIZE1) << ' ' << maxElem(series2, SIZE2) << std::endl;

	return 0;
}
