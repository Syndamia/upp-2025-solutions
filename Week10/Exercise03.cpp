#include <iostream>

int main() {
	unsigned int rows, cols;
	std::cin >> rows >> cols;

	unsigned int** mat = new unsigned int*[rows];
	for (unsigned int row = 0; row < rows; row++) {
		mat[row] = new unsigned int[cols];

		for (unsigned int col = 0; col < cols; col++)
			std::cin >> mat[row][col];
	}

	/* По принцип можем да решим задачата, все едно е динамична памет,
	 * тоест да разменяме първи елемент от първи ред с първи от последен
	 * ред, втори от първи ред с втори от последен ред и так. нат.
	 *
	 * Но тук, по-простия начин е да разменим указатели, което също е по-ефикасно.
	 */
	for (unsigned int row = 0; row < rows / 2; row++) {
		unsigned int* temp = mat[row];
		mat[row] = mat[rows - 1 - row];
		mat[rows - 1 - row] = temp;
	}

	for (unsigned int row = 0; row < rows; row++) {
		for (unsigned int col = 0; col < cols; col++)
			std::cout << mat[row][col] << ' ';
		std::cout << std::endl;
	}

	for (unsigned int row = 0; row < rows; row++)
		delete[] mat[row];
	delete[] mat;

	return 0;
}
