#include <iostream>

int largest(int** mat, unsigned int rows, unsigned int cols) {
	int max = mat[0][0];

	for (unsigned int row = 0; row < rows; row++)
		for (unsigned int col = 0; col < cols; col++)
			if (mat[row][col] > max)
				max = mat[row][col];

	return max;
}

int main() {
	int rows, cols;
	std::cin >> rows >> cols;

	int** mat = new int*[rows];
	for (unsigned int row = 0; row < rows; row++) {
		mat[row] = new int[cols];

		for (unsigned int col = 0; col < cols; col++)
			std::cin >> mat[row][col];
	}

	std::cout << largest(mat, rows, cols) << std::endl;

	for (unsigned int row = 0; row < rows; row++)
		delete[] mat[row];
	delete[] mat;

	return 0;
}
