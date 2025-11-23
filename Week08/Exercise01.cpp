#include <iostream>

/* Тази задача може да се реши без матрици.
 * Все пак идеята е да упражним точно тях.
 */

int main() {
	const unsigned int SIZE = 5;
	int mat[SIZE][SIZE];

	for (unsigned int i = 0; i < SIZE; i++)
		for (unsigned int j = 0; j < SIZE; j++)
			std::cin >> mat[i][j];

	unsigned int countZeroes = 0;
	for (unsigned int i = 0; i < SIZE; i++)
		for (unsigned int j = 0; j < SIZE; j++)
			countZeroes += mat[i][j] == 0;

	/* Бройката нули е повече от бройката на всички елементи които не са нули.
	 * Алтернативно, може и да се пази втори брояч за ненулеви елементи.
	 */
	if (countZeroes > SIZE * SIZE - countZeroes)
		std::cout << "Sparse" << std::endl;
	else
		std::cout << "Not sparse" << std::endl;

	return 0;
}
