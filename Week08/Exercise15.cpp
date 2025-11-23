#include <iostream>

const int ROWS = 9, COLS = 7;

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a < b ? a : b;
}

double abs(double x) {
	return x < 0 ? -x : x;
}

bool checkSurroundingCells(const double mat[ROWS][COLS], int row, int col, double maxDiff)
{
	for (int r = max(0, row - 1); r <= min(ROWS - 1, row + 1); r++) {
		for (int c = max(0, col - 1); c <= min(COLS - 1, col + 1); c++) {
			if (abs(mat[r][c] - mat[row][col]) >= maxDiff)
				return false;
		}
	}
	return true;
}

int main() {
	double mat[ROWS][COLS];
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			std::cin >> mat[i][j];

	double maxDiff;
	std::cin >> maxDiff;

	bool smooth = true;
	for (int i = 0; i < ROWS && smooth; i++)
		for (int j = 0; j < COLS && smooth; j++)
			smooth = checkSurroundingCells(mat, i, j, maxDiff);

	if (smooth)
		std::cout << "Smooth" << std::endl;
	else
		std::cout << "Not smooth" << std::endl;

	return 0;
}
