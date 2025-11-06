#include <iostream>

int main() {
	const unsigned int SIZE = 4;

	unsigned long numbers[SIZE];
	for (int i = 0; i < SIZE; i++)
		std::cin >> numbers[i];

	unsigned long max_number = 0;

	/* Това решение е ГРОЗНО!
	 * Има по-добри начини да се реализира, но тук се показва
	 * доста видно комбинаториката, т.е. как се избират индексите.
	 */

	// 4 избора за първото число
	for (int i = 0; i < SIZE; i++) {

		// 3 избора за второто число
		for (int j = 0; j < SIZE; j++) {
			if (j == i) continue;

			// 2 избора за третото число
			for (int k = 0; k < SIZE; k++) {
				if (k == j || k == i) continue;

				// 1 избор за четвъртото число
				for (int l = 0; l < SIZE; l++) {
					if (l == k || l == j || l == i) continue;

					unsigned long current_number = numbers[i] * 1000000000 +
					                               numbers[j] * 1000000    +
					                               numbers[k] * 1000       +
					                               numbers[l];
					if (current_number > max_number)
						max_number = current_number;
				}
			}
		}
	}

	std::cout << max_number << std::endl;

	return 0;
}
