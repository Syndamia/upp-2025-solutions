#include <iostream>

const unsigned int SIZE = 5;

/* counts масива съдържа бройката на всеки тип сграда в околност/съседство на тази на подадените индекси.
 * counts[0] - бройка жилищни
 * counts[1] - бройка търговски
 * counts[2] - бройка офисни
 * counts[3] - бройка луксозни
 */
void surroundingBuildings(const unsigned short mat[SIZE][SIZE], unsigned int row, unsigned int col, unsigned short counts[4]) {
	for (unsigned int type = 0; type < 4; type++)
		counts[type] = 0;

	/* Възползваме се от факта, че сградите ни се представят като числата от 1 до 4 вкл.
	 * Намаляйки с единица, те се превръщат в 0 до 3 вкл. и стават валидни индекси в counts.
	 */
	if (0 < row)        counts[mat[row - 1][col] - 1]++;
	if (row < SIZE - 1) counts[mat[row + 1][col] - 1]++;
	if (0 < col)        counts[mat[row][col - 1] - 1]++;
	if (col < SIZE - 1) counts[mat[row][col + 1] - 1]++;
}

int main() {
	/* Изкушаващо е да спестим малко памет и да използваме unsigned char, обаче
	 * тогава std::cin ще вкарва стойностите като букви, не като числа.
	 * Реално, винаги можем да ги превърнем обратно в числовите им стойности, но
	 * така е по-лесно.
	 */
	unsigned short city[SIZE][SIZE];

	for (unsigned int i = 0; i < SIZE; i++)
		for (unsigned int j = 0; j < SIZE; j++)
			std::cin >> city[i][j];

	unsigned short surroundings[4] = { 0 };

	bool valid = true;
	for (unsigned int i = 0; i < SIZE && valid; i++) {
		for (unsigned int j = 0; j < SIZE && valid; j++) {
			surroundingBuildings(city, i, j, surroundings);

			valid = (city[i][j] == 1) ||
			        (city[i][j] == 2 && surroundings[0] >= 1) ||
			        (city[i][j] == 3 && surroundings[0] >= 1 && surroundings[1] >= 1) ||
			        (city[i][j] == 4 && surroundings[0] >= 1 && surroundings[1] >= 1 && surroundings[2] >= 1);
		}
	}

	if (valid)
		std::cout << "Valid" << std::endl;
	else
		std::cout << "Invalid" << std::endl;

	return 0;
}
