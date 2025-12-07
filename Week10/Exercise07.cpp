#include <iostream>

bool** allocateMatrix(unsigned int rows, unsigned int cols) {
	bool** mat = new bool*[rows];
	for (unsigned int row = 0; row < rows; row++) {
		mat[row] = new bool[cols];
		for (unsigned int col = 0; col < cols; col++)
			mat[row][col] = false;
	}

	return mat;
}

void deleteMatrix(bool** matrix, unsigned int rows) {
	for (unsigned int row = 0; row < rows; row++)
		delete[] matrix[row];
	delete[] matrix;
}

int main() {
	unsigned int allocatedRows = 4, allocatedCols = 4;
	bool** mat = allocateMatrix(allocatedRows, allocatedCols);

	int row = 0, col = 0;
	while (row >= 0 && col >= 0 && !mat[row][col]) {
		mat[row][col] = true;

		char dir;
		std::cin >> dir;
		switch (dir) {
			case 'r': col++; break;
			case 'l': col--; break;
			case 'u': row--; break;
			case 'd': row++; break;
		}

		if (row >= allocatedRows || col >= allocatedCols) {
			bool** largerMat = allocateMatrix(allocatedRows * 2, allocatedCols * 2);

			for (unsigned int row = 0; row < allocatedRows; row++)
				for (unsigned int col = 0; col < allocatedCols; col++)
					largerMat[row][col] = mat[row][col];

			deleteMatrix(mat, allocatedRows);
			mat = largerMat;

			allocatedRows *= 2;
			allocatedCols *= 2;
		}
	}

	unsigned int i, j;
	std::cin >> i >> j;
	if (i < allocatedRows && j < allocatedCols && mat[i][j]) {
		std::cout << "Visited" << std::endl;
	}
	else {
		std::cout << "Not visited" << std::endl;
	}

	deleteMatrix(mat, allocatedRows);

	return 0;
}
