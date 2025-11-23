#include <iostream>

const unsigned int SIZE_PAT = 3;

bool matchesPattern(const char pattern[SIZE_PAT][SIZE_PAT], const char* input, unsigned int inputRows, unsigned int inputCols) {
	for (unsigned int i = 0; i < SIZE_PAT; i++) {
		for (unsigned int j = 0; j < SIZE_PAT; j++) {
			/* За повече информация защо така индексираме в input, вижте
			 * https://syndamia.com/teaching/upp-2025/cpp-pitfalls/#-int73-vs-int3-vs-int
			 */
			if (pattern[i][j] != '*' && pattern[i][j] != input[i * inputRows + j])
				return false;
		}
	}
	return true;
}

int main() {
	char pattern[SIZE_PAT][SIZE_PAT];

	for (unsigned int i = 0; i < SIZE_PAT; i++)
		for (unsigned int j = 0; j < SIZE_PAT; j++)
			std::cin >> pattern[i][j];

	const unsigned int SIZE = 6;
	char inp[SIZE][SIZE];

	for (unsigned int i = 0; i < SIZE; i++)
		for (unsigned int j = 0; j < SIZE; j++)
			std::cin >> inp[i][j];

	unsigned int matches = 0;
	for (unsigned int i = 0; i <= SIZE - SIZE_PAT; i++) {
		for (unsigned int j = 0; j <= SIZE - SIZE_PAT; j++) {
			/* За повече информация защо подаваме такива стойности на функцията,
			 * вижте решението на 3та задача.
			 */
			matches += matchesPattern(pattern, (const char*)inp + i * SIZE + j, SIZE, SIZE);
		}
	}

	std::cout << matches << std::endl;

	return 0;
}
