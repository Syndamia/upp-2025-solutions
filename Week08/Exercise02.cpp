#include <iostream>

void rowSum(const unsigned int* matrix, unsigned int rows, unsigned int cols, unsigned int* sum) {
	for (unsigned int row = 0; row < rows; row++)
		for (unsigned int col = 0; col < cols; col++)
			/* За повече информация защо така индексираме в matrix, вижте
			 * https://syndamia.com/teaching/upp-2025/cpp-pitfalls/#-int73-vs-int3-vs-int
			 */
			sum[col] += matrix[row * cols + col];
}

int main() {
	const unsigned int ROWS = 7, COLS = 3;
	unsigned int mat[ROWS][COLS];

	for (unsigned int i = 0; i < ROWS; i++)
		for (unsigned int j = 0; j < COLS; j++)
			std::cin >> mat[i][j];

	unsigned int sum[COLS] = { 0 };
	rowSum((const unsigned int*)mat, ROWS, COLS, sum);

	for (unsigned int col = 0; col < COLS; col++)
		std::cout << sum[col] << ' ';
	std::cout << std::endl;

	return 0;
}
