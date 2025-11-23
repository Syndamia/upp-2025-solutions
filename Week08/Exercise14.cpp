#include <iostream>

int main() {
	const unsigned int ROWS = 6, COLS = 3;

	double vec[ROWS];
	for (unsigned int i = 0; i < ROWS; i++)
		std::cin >> vec[i];

	double mat[ROWS][COLS];
	for (unsigned int i = 0; i < ROWS; i++)
		for (unsigned int j = 0; j < COLS; j++)
			std::cin >> mat[i][j];

	double mult[COLS] = { 0.0 };
	for (unsigned int col = 0; col < COLS; col++)
		for (unsigned int row = 0; row < ROWS; row++)
			mult[col] += vec[row] * mat[row][col];

	for (unsigned int i = 0; i < COLS; i++)
		std::cout << mult[i] << ' ';
	std::cout << std::endl;

	return 0;
}
