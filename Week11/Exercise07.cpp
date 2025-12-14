#include <iostream>

int main() {
	const unsigned PATTERN_SIZE = 5;
	char pattern[PATTERN_SIZE + 1];
	std::cin.getline(pattern, PATTERN_SIZE+1);

	unsigned allocated = 8, size = 0;
	char* text = new char[allocated];

	char curr;
	std::cin.get(curr);
	while (curr != '\n') {
		text[size++] = curr;
		std::cin.get(curr);

		// Реоразмеряване
		if (size >= allocated) {
			allocated *= 2;
			char* newSentenceArray = new char[allocated];

			for (unsigned i = 0; i < size; i++)
				newSentenceArray[i] = text[i];

			delete[] text;
			text = newSentenceArray;
		}
	}
	text[size] = '\0';

	unsigned matches = 0;
	for (unsigned i = 0; i < size - PATTERN_SIZE + 1; i++) {
		bool allMatch = true;

		// Проверяваме дали от текущата буква в текста, нататък,
		// низа съвпада с шаблона.
		for (unsigned j = 0; j < PATTERN_SIZE; j++)
			allMatch = allMatch && (text[i + j] == pattern[j]);

		matches += allMatch;
	}

	std::cout << matches << std::endl;

	delete[] text;

	return 0;
}
