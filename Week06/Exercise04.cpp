#include <iostream>

int main() {
	const unsigned int SIZE_FIRST = 15, SIZE_SECOND = 5;
	int first[SIZE_FIRST], second[SIZE_SECOND];

	for (unsigned int i = 0; i < SIZE_FIRST; i++)
		std::cin >> first[i];
	for (unsigned int i = 0; i < SIZE_SECOND; i++)
		std::cin >> second[i];

	unsigned int counts[SIZE_SECOND] = { 0 };
	for (unsigned int i = 0; i < SIZE_FIRST; i++) {
		for (unsigned int j = 0; j < SIZE_SECOND; j++) {
			if (first[i] == second[j]) {
				counts[j]++;
				break;
			}
		}
	}

	for (unsigned int i = 0; i < SIZE_SECOND; i++)
		std::cout << counts[i] << ' ';
	std::cout << std::endl;

	return 0;
}
