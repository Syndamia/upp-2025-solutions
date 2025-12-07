#include <iostream>

int main() {
	unsigned int allocated = 4, elements = 0;
	int* numbers = new int[allocated];

	int temp;
	std::cin >> temp;
	while (temp != 0) {
		numbers[elements++] = temp;
		std::cin >> temp;

		/* Реоразмеряваме, ако не ни стига мястото
		 */
		if (elements >= allocated) {
			allocated *= 2;
			int* moreNumbers = new int[allocated];

			for (unsigned int i = 0; i < elements; i++)
				moreNumbers[i] = numbers[i];

			delete[] numbers;
			numbers = moreNumbers;
		}
	}

	if (elements == 1) {
		std::cout << numbers[0] << std::endl;
	}
	else if (elements > 1) {
		/* Нарочно използвам int, за да е по-разбираемо кои индекси ползваме,
		 * иначе този тип е грешен, понеже elements е unsigned int
		 */
		for (int i = elements - 2; i >= 0; i--)
			numbers[i] += numbers[i + 1];

		for (unsigned int i = 0; i < elements; i++)
			std::cout << numbers[i] << ' ';
		std::cout << std::endl;
	}

	delete[] numbers;

	return 0;
}
