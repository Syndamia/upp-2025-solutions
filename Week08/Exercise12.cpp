#include <iostream>

const unsigned int SIZE = 10;
const double STEP = 0.001;

void swap(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}

void fill(char mat[SIZE][SIZE], char filler) {
	for (unsigned int i = 0; i < SIZE; i++)
		for (unsigned int j = 0; j < SIZE; j++)
			mat[i][j] = filler;
}

int main() {
	double startX, startY, endX, endY;
	std::cin >> startX >> startY >> endX >> endY;

	char mat[SIZE][SIZE];
	fill(mat, ' ');

	/* Преместваме началната точка към крайната точка, следвайки отсечката.
	 * Все едно една мравка е започнала в началната точка и се движи върху правата,
	 * докато стигне крайната точка.
	 *
	 * Разменяме двете точки, защото правим изчислението все едно началната точка е
	 * в ляво от крайната.
	 */

	if (startX > endX) {
		swap(startX, endX);
		swap(startY, endY);
	}

	double dx = (endX - startX) * STEP, dy = (endY - startY) * STEP;

	while (startX < endX) {
		mat[(int)startY][(int)startX] = 'x';
		startX += dx;
		startY += dy;
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			std::cout << mat[i][j];
		std::cout << std::endl;
	}

	return 0;
}
