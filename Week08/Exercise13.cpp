#include <iostream>

int main() {
	const unsigned int SIZE = 8;
	char mat[SIZE][SIZE];

	for (unsigned int i = 0; i < SIZE; i++)
		for (unsigned int j = 0; j < SIZE; j++)
			std::cin >> mat[i][j];

	int minRow = SIZE, maxRow = 0, minCol = SIZE, maxCol = 0;
	for (unsigned int i = 0; i < SIZE; i++) {
		for (unsigned int j = 0; j < SIZE; j++) {
			if (mat[i][j] == '+') {
				if (i < minCol) minCol = i;
				if (i > maxCol) maxCol = i;
				if (j < minRow) minRow = j;
				if (j > maxRow) maxRow = j;
			}
		}
	}

	if (minRow == SIZE) {
		minRow = 1;
		minCol = 1;
	}

	std::cout << (maxCol - minCol + 1) << ' ' << (maxRow - minRow + 1) << std::endl;

	return 0;
}
