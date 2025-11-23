#include <iostream>

/* В това решение използваме int за размери, вместо unsigned int, защото
 * правим изваждания, които се обработват по-лесно като можеш да имаш отрицателни числа.
 * Може да се преработи с unsigned int (и окуражавам да го направите), но кода става
 * по-досаден и грозен.
 */
const int SIZE = 10;

int clamp(int value, int min, int max) {
	if (value < min) return min;
	if (value > max) return max;
	return value;
}

void sumCells(const unsigned int mat[SIZE][SIZE],
              int startRow, int endRow,
              int startCol, int endCol,
              unsigned int &sum, unsigned int &count)
{
	startRow = clamp(startRow, 0, SIZE - 1);
	endRow   = clamp(endRow,   0, SIZE - 1);
	startCol = clamp(startCol, 0, SIZE - 1);
	endCol   = clamp(endCol,   0, SIZE - 1);

	for (int row = startRow; row <= endRow; row++) {
		for (int col = startCol; col <= endCol; col++) {
			sum += mat[row][col];
			count++;
		}
	}
}

double averageCells(const unsigned int mat[SIZE][SIZE], int row, int col, unsigned int radius) {
	unsigned int sum = 0, sumCount = 0;

	sumCells(mat, row - radius, row + radius, col - radius, col + radius, sum, sumCount);

	return (double)sum / sumCount;
}

int main() {
	unsigned int mat[SIZE][SIZE];

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			std::cin >> mat[i][j];

	unsigned int radius;
	std::cin >> radius;

	double blurred[SIZE][SIZE] = { 0 };

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			blurred[i][j] = averageCells(mat, i, j, radius);

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			std::cout << blurred[i][j] << ' ';
		std::cout << std::endl;
	}

	return 0;
}
