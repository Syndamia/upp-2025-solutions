#include <iostream>

double** inputMatrix(unsigned int& rows, unsigned int& cols) {
	std::cin >> rows >> cols;

	double** mat = new double*[rows];
	for (unsigned int row = 0; row < rows; row++) {
		mat[row] = new double[cols];

		for (unsigned int col = 0; col < cols; col++)
			std::cin >> mat[row][col];
	}

	/* Използваме динамична памет, тя не се унищожава (освобождава)
	 * автоматично, което означава че можем да върнем указателя и
	 * всичко ще работи коректно.
	 */
	return mat;
}

void deleteMatrix(double** mat, unsigned int rows) {
	for (unsigned int row = 0; row < rows; row++)
		delete[] mat[row];
	delete[] mat;
}

int main() {
	unsigned int rowsA, colsA, rowsB, colsB;
	double** matA = inputMatrix(rowsA, colsA), **matB = inputMatrix(rowsB, colsB);

	if (colsA != rowsB) {
		std::cout << "Cannot multiply!" << std::endl;
	}
	else {
		double** matC = new double*[rowsA];

		for (unsigned int row = 0; row < rowsA; row++) {
			matC[row] = new double[colsB];

			for (unsigned int col = 0; col < colsB; col++) {
				matC[row][col] = 0;

				for (unsigned int i = 0; i < colsA; i++) {
					matC[row][col] += matA[row][i] * matB[i][col];
				}
			}
		}

		for (unsigned int row = 0; row < rowsA; row++) {
			for (unsigned int col = 0; col < colsB; col++)
				std::cout << matC[row][col] << ' ';
			std::cout << std::endl;
		}

		deleteMatrix(matC, rowsA);
	}

	deleteMatrix(matA, rowsA);
	deleteMatrix(matB, rowsB);

	return 0;
}
