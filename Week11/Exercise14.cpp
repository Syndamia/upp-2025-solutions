#include <iostream>

char* getLine() {
	unsigned allocated = 8, size = 0;
	char* sentence = new char[allocated];

	char curr;
	std::cin.get(curr);
	while (curr != '\n') {
		sentence[size++] = curr;
		std::cin.get(curr);

		// Реоразмеряване
		if (size >= allocated) {
			allocated *= 2;
			char* newSentenceArray = new char[allocated];

			for (unsigned i = 0; i < size; i++)
				newSentenceArray[i] = sentence[i];

			delete[] sentence;
			sentence = newSentenceArray;
		}
	}
	sentence[size] = '\0';

	return sentence;
}

int main() {
	char* first = getLine(), *second = getLine();

	bool foundCharacters[256] = { 0 };
	for (char* f = first; *f != '\0'; f++)
		foundCharacters[*f] = true;

	bool isAnagram = true;
	for (char* s = second; *s != '\0' && isAnagram; s++) {
		// Малките букви са отместени от главните с 32,
		// тоест всяка главна буква + 32 прави съответната малка буква
		// (и обратно).

		if ('A' <= *s && *s <= 'Z') {
			isAnagram = foundCharacters[*s] || foundCharacters[*s + 32];
		}
		else if ('a' <= *s && *s <= 'z') {
			isAnagram = foundCharacters[*s] || foundCharacters[*s - 32];
		}
	}

	if (isAnagram)
		std::cout << "Anagram" << std::endl;
	else
		std::cout << "Not an anagram" << std::endl;

	delete[] first;
	delete[] second;

	return 0;
}
