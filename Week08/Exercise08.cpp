#include <iostream>

const unsigned int SIZE = 3;

void inputMatrix(unsigned int mat[SIZE][SIZE]) {
	for (unsigned int i = 0; i < SIZE; i++)
		for (unsigned int j = 0; j < SIZE; j++)
			std::cin >> mat[i][j];
}

unsigned int multiplyRowCol(const unsigned int matA[SIZE][SIZE], const unsigned int matB[SIZE][SIZE], unsigned int rowA, unsigned int colB) {
	unsigned int result = 0;
	for (unsigned int i = 0; i < SIZE; i++)
		result += matA[rowA][i] * matB[i][colB];
	return result;
}

void multiplyMatrices(const unsigned int matA[SIZE][SIZE], const unsigned int matB[SIZE][SIZE], unsigned int out[SIZE][SIZE]) {
	for (unsigned int row = 0; row < SIZE; row++)
		for (unsigned int col = 0; col < SIZE; col++)
			out[row][col] = multiplyRowCol(matA, matB, row, col);
}

int main() {
	unsigned int matA[SIZE][SIZE], matB[SIZE][SIZE];
	inputMatrix(matA);
	inputMatrix(matB);

	unsigned int mult[SIZE][SIZE];
	multiplyMatrices(matA, matB, mult);

	for (unsigned int row = 0; row < SIZE; row++) {
		for (unsigned int col = 0; col < SIZE; col++)
			std::cout << mult[row][col] << ' ';
		std::cout << std::endl;
	}

	return 0;
}
