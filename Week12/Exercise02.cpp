#include <iostream>

unsigned int findSpace(const char* text, unsigned int start, unsigned int size) {
	for (unsigned int i = start; i < size; i++)
		if (text[i] == ' ')
			return i;
	return size;
}

void fitToColumns(char* text, unsigned int size, unsigned int columns) {
	unsigned indexInColumn = 0;
	unsigned int lastSpace = size;

	for (unsigned int i = 0; i < size; i++) {
		if (text[i] == ' ')
			lastSpace = i;

		if (indexInColumn == columns) {
			// Ако следващия знак е шпация, разделяме реда на него,
			// вместо на предходна шпация (ако има такава).
			// Това побира по-добре нашите полета и оправя пример 3.
			if (i + 1 < size && text[i + 1] == ' ')
				lastSpace = i + 1;
			else if (i + 1 == size)
				return;

			if (lastSpace >= size)
				lastSpace = findSpace(text, i, size);

			if (lastSpace >= size)
				return;

			text[lastSpace] = '\n';
			i = lastSpace + 1;

			indexInColumn = 0;
			lastSpace = size;
		}
		else {
			indexInColumn++;
		}
	}
}

char* getInput(unsigned &allocated, unsigned &size);

int main() {
	unsigned int allocated, size;
	char* text = getInput(allocated, size);

	unsigned int columns;
	std::cin >> columns;

	fitToColumns(text, size, columns - 1);
	std::cout << text << std::endl;

	delete[] text;

	return 0;
}

char* getInput(unsigned &allocated, unsigned &size) {
	allocated = 8;
	size = 0;

	char* input = new char[allocated];

	char curr;
	std::cin.get(curr);
	while (curr != '\n') {
		input[size++] = curr;
		std::cin.get(curr);

		// Реоразмеряване
		if (size >= allocated) {
			allocated *= 2;
			char* newSentenceArray = new char[allocated];

			for (unsigned i = 0; i < size; i++)
				newSentenceArray[i] = input[i];

			delete[] input;
			input = newSentenceArray;
		}
	}
	input[size] = '\0';

	return input;
}
