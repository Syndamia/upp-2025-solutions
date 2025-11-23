#include <iostream>

void subMatrix(const double* inmat, unsigned int inRows, unsigned int inCols,
               double* outmat,      unsigned int outRows, unsigned int outCols)
{
	for (unsigned int row = 0; row < outRows; row++)
		for (unsigned int col = 0; col < outCols; col++)
			/* За повече информация защо така индексираме в матриците, вижте
			 * https://syndamia.com/teaching/upp-2025/cpp-pitfalls/#-int73-vs-int3-vs-int
			 */
			outmat[row * inCols + col] = inmat[row * inCols + col];
}

int main() {
	const unsigned int ROWS = 6, COLS = 6;
	double mat[ROWS][COLS];

	for (unsigned int i = 0; i < ROWS; i++)
		for (unsigned int j = 0; j < COLS; j++)
			std::cin >> mat[i][j];

	unsigned int startRow, startCol, rows, cols;
	std::cin >> startCol >> startRow >> cols >> rows;

	double submat[ROWS][COLS] = { 0 };
	/* По условие се иска функцията да попълва елементите от горния ляв ъгъл на матрицата.
	 * Това означава, че трябва да променим горния ляв ъгъл къде е (т.е. да съответства
	 * на елемента на началните позиции).
	 *
	 * Един лош ефект от това е, че подадените размери (особено броя колони) на входната
	 * матрица са спрямо цялата матрица, не подматрицата която искаме.
	 * Тоест, на теория, функцията може да излезе извън паметта на матрицата, заради
	 * начина по който индексираме.
	 *
	 * Интересното е, че ако матрицата беше динамично заделена, това нямаше да е проблем.
	 * По тази тема ще говорим в бъдеще.
	 */
	subMatrix((const double*)mat + startRow * COLS + startCol, ROWS, COLS,
	          (double*)submat, rows, cols);

	for (unsigned int row = 0; row < rows; row++) {
		for (unsigned int col = 0; col < cols; col++)
			std::cout << submat[row][col] << ' ';
		std::cout << std::endl;
	}

	return 0;
}
