#include <iostream>

void swap(double &a, double &b) {
	double temp = a;
	a = b;
	b = temp;
}

void swapColumns(double* mat, unsigned int rows, unsigned int cols, unsigned int column1, unsigned int column2) {
	if (column1 >= cols || column2 >= cols)
		return;

	for (unsigned int row = 0; row < rows; row++)
		/* За повече информация защо така индексираме в матриците, вижте
		 * https://syndamia.com/teaching/upp-2025/cpp-pitfalls/#-int73-vs-int3-vs-int
		 */
		swap(mat[row * cols + column1], mat[row * cols + column2]);
}

int main() {
	const unsigned int ROWS = 3, COLS = 5;
	double mat[ROWS][COLS];

	for (unsigned int i = 0; i < ROWS; i++)
		for (unsigned int j = 0; j < COLS; j++)
			std::cin >> mat[i][j];

	unsigned int col1, col2;
	std::cin >> col1 >> col2;

	swapColumns((double*)mat, ROWS, COLS, col1, col2);

	for (unsigned int row = 0; row < ROWS; row++) {
		for (unsigned int col = 0; col < COLS; col++)
			std::cout << mat[row][col] << ' ';
		std::cout << std::endl;
	}

	return 0;
}
