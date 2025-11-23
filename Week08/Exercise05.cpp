#include <iostream>

const unsigned int SIZE = 3;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void transpose(int mat[SIZE][SIZE]) {
	/* Има по-проста имплементация за матрица 3x3, но тази работи за всякакъв размер матрица.
	 * Каква е идеята: движим се по диагоналите над главния и разменяме елементите със съответния
	 * диагонал под главния.
	 *
	 * Ето така обикаляме, като числото показва използваната diagDist и плюсовете маркират главния диагонал:
	 * +1234
	 * 1+123
	 * 21+12
	 * 321+1
	 * 4321+
	 *
	 * Би трябвало да е очевидно, че първия ред ще участва във всеки диагонал.
	 * Затова, почваме от елемента на първия ред, който участва в текущия диагонал, и от там
	 * увеличаваме реда и колоната на всяка итерация.
	 *
	 * Когато имаме позиция над главния диагонал, стигаме до тази под главния като просто
	 * разменим реда и колоната.
	 *
	 * Ако не разбирате някои от тези сметки/индексирания, просто си разпишете някой по-голям пример.
	 */
	for (unsigned int diagDist = 1; diagDist < SIZE; diagDist++)
		for (unsigned int diagElem = 0; diagElem + diagDist < SIZE; diagElem++)
			swap(mat[diagElem][diagElem + diagDist], mat[diagElem + diagDist][diagElem]);
}

int main() {
	int mat[SIZE][SIZE];

	for (unsigned int i = 0; i < SIZE; i++)
		for (unsigned int j = 0; j < SIZE; j++)
			std::cin >> mat[i][j];

	transpose(mat);

	for (unsigned int i = 0; i < SIZE; i++) {
		for (unsigned int j = 0; j < SIZE; j++)
			std::cout << mat[i][j] << ' ';
		std::cout << std::endl;
	}

	return 0;
}
