#include <iostream>

int main() {
	const unsigned int SIZE = 11;
	unsigned int pascal[SIZE][SIZE] = { 0 };

	for (unsigned int i = 0; i < SIZE; i++)
		pascal[i][0] = pascal[i][i] = 1;

	for (unsigned int row = 2; row < SIZE; row++)
		for (unsigned int col = 1; col < row; col++)
			/* Елемента над и в ляво на текущия, сумирано с елемента над текущия.
			 */
			pascal[row][col] = pascal[row - 1][col - 1] + pascal[row - 1][col];

	for (unsigned int row = 0; row < SIZE; row++) {
		for (unsigned int col = 0; col < SIZE; col++)
			std::cout << pascal[row][col] << ' ';
		std::cout << std::endl;
	}

	return 0;
}
