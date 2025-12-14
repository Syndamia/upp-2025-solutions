#include <iostream>

char* getField() {
	unsigned allocated = 8, size = 0;
	char* output = new char[allocated];

	char curr;
	std::cin.get(curr);

	while (curr != ' ' && curr != '\n' && curr != '\0') {
		output[size++] = curr;
		std::cin.get(curr);

		// Реоразмеряване
		if (size >= allocated) {
			allocated *= 2;
			char* newSentenceArray = new char[allocated];

			for (unsigned i = 0; i < size; i++)
				newSentenceArray[i] = output[i];

			delete[] output;
			output = newSentenceArray;
		}
	}
	output[size] = '\0';

	return output;
}

int main() {
	char* search = getField(), *pattern = getField();

	// char е 8 битово, което означава че има 2^^8 = 256
	// на брой различни възможни стойности.
	// Знаем, че всяка буква всъщност е едно число, затова
	// можем директно да го използваме като индекс.

	unsigned occurrences[256] = { 0 };
	for (const char* ser = search; *ser != '\0'; ser++)
		occurrences[*ser]++;

	unsigned sumOccurrences = 0;
	for (const char* pat = pattern; *pat != '\0'; pat++)
		sumOccurrences += occurrences[*pat];

	std::cout << sumOccurrences << std::endl;

	delete[] search;
	delete[] pattern;

	return 0;
}
