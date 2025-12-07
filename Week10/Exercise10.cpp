#include <iostream>

unsigned int** newHourglassMatrix(unsigned int size) {
	unsigned int** mat = new unsigned int*[size];
	for (unsigned int row = 0; row < size / 2; row++) {
		mat[row] = new unsigned int[size - row * 2];
		mat[size - 1 - row] = new unsigned int[size - row * 2];
	}

	if (size % 2 == 1)
		mat[size / 2] = new unsigned int[1];
	return mat;
}

void deleteHourglassMatrix(unsigned int** mat, unsigned int size) {
	for (unsigned int row = 0; row < size / 2; row++) {
		delete[] mat[row];
		delete[] mat[size - 1 - row];
	}
	if (size % 2 == 1)
		delete[] mat[size / 2];
	delete[] mat;
}

void inputHourglassMatrix(unsigned int** mat, unsigned int size) {
	for (unsigned int row = 0; row < size; row++) {
		unsigned int cols = (row < size / 2) ? size - row * 2 : size - (size - 1 - row) * 2;
		for (unsigned int col = 0; col < cols; col++)
			std::cin >> mat[row][col];
	}
}

void outputHourglassCountour(unsigned int** mat, unsigned int size) {
	// Първи ред
	for (unsigned int col = 0; col < size; col++)
		std::cout << mat[0][col] << ' ';

	/* Втори диагонал */
	// От първи ред до преди средния изкарваме последния елемент на вс ред
	for (unsigned int row = 1; row < size / 2; row++)
		std::cout << mat[row][size - row * 2 - 1] << ' ';
	// От средния ред до последния изкарваме първия елемент на вс ред
	for (unsigned int row = size / 2; row < size; row++)
		std::cout << mat[row][0] << ' ';

	// Последен ред
	for (unsigned int col = 1; col < size; col++)
		std::cout << mat[size - 1][col] << ' ';

	/* Главен диагонал */
	// От последния ред до средния изкарваме последния елемент на вс ред
	for (unsigned int row = size - 2; row >= size / 2; row--)
		std::cout << mat[row][size - (size - 1 - row) * 2 - 1] << ' ';
	// От преди средния ред до първия ред изкарваме първия елемент на вс ред
	for (unsigned int row = size / 2; row > 0; row--)
		std::cout << mat[row - 1][0] << ' ';

	std::cout << std::endl;
}

int main() {
	unsigned int size;
	std::cin >> size;
	unsigned int** hmat = newHourglassMatrix(size);
	inputHourglassMatrix(hmat, size);

	outputHourglassCountour(hmat, size);

	deleteHourglassMatrix(hmat, size);
	return 0;
}
