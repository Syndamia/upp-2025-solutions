#include <iostream>

bool strneq(const char* str1, const char* str2, unsigned n) {
	// Грозно е, но е добро упражнение за реда на операции
	while (*str1 != '\0' && *str2 != '\0' && n-- > 0) {
		if (*str1++ != *str2++)
			return false;
	}
	return true;
}

void printField(const char* str) {
	while (*str != ' ' && *str != '\0') {
		std::cout << *str++;
	}
}

int main() {
	// Кодът е написан, допускайки че "end" е единствената
	// възможна дума, обозначаваща край.
	// Как може да се пренапише, така че да можем да си
	// изберем произволен низ, обозначаващ край?

	unsigned allocated = 8, size = 0;
	char* text = new char[allocated];

	std::cin.get(text[size++]);
	std::cin.get(text[size++]);
	std::cin.get(text[size++]);

	char curr;
	while (!strneq(text + size - 3, "end", 3)) {
		std::cin.get(curr);
		text[size++] = curr;

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

	// Обикаляме отзад-напред. В момента в който стигнем началото на поле
	// (а именно, не-шпация преди която имаме шпация), тогава изкарваме
	// полето. Тоест започваме временно да се движим напред, докато не
	// сме изразходили буквите, съставящи полето.
	//
	// Тази схема очевидно оставя полето от първата буква непринтирано.

	bool prevNonSpace = false;
	for (int i = size - 1; i >= 0; i--) {
		if (text[i] != ' ') {
			prevNonSpace = true;
			continue;
		}

		if (prevNonSpace) {
			printField(text + i + 1);
			prevNonSpace = false;
		}

		std::cout << text[i];
	}
	printField(text);
	std::cout << std::endl;

	delete[] text;

	return 0;
}
