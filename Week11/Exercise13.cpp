#include <iostream>

unsigned fnvHash(const char* str) {
	unsigned hash = 2166136261;
	while (*str != '\0') {
		hash *= 16777619;
		hash ^= *str;
		str++;
	}
	return hash;
}

int main() {
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

	std::cout << fnvHash(sentence) << std::endl;

	delete[] sentence;

	return 0;
}
