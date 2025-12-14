#include <iostream>

/* Предлагам три решения на тази задача */

unsigned countLetters(const char* str) {
	unsigned count = 0;
	while (*str != '\0') {
		count += ('A' <= *str && *str <= 'Z') ||
		         ('a' <= *str && *str <= 'z');
		++str;
	}
	return count;
}

// Избираме си максимален размер за низа
void solution1() {
	const unsigned MAX_LENGTH = 1024;

	char sentence[MAX_LENGTH];
	std::cin.getline(sentence, MAX_LENGTH, '.');

	std::cout << countLetters(sentence) << std::endl;
}

// Низа може да бъде произволно дълъг
void solution2() {
	// Заделяме памет за низа, следим колко букви сме вкарали в низа.
	// Ако запълним заделената памет, реоразмеряваме масива (правим
	// го по-голям).

	unsigned allocated = 8, size = 0;
	char* sentence = new char[allocated];

	char curr;
	std::cin.get(curr);
	while (curr != '.') {
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

	std::cout << countLetters(sentence) << std::endl;

	delete[] sentence;
}

// В тази конкретна задача, не е нужно да запазваме
// целия низ и после да гледаме буквите, можем директно
// да анализираме входа буква по буква
void solution3() {
	unsigned count = 0;

	char curr;
	std::cin.get(curr);
	while (curr != '.') {
		count += ('A' <= curr && curr <= 'Z') ||
		         ('a' <= curr && curr <= 'z');
		std::cin.get(curr);
	}

	std::cout << count << std::endl;
}

int main() {
	// solution1();
	// solution2();
	solution3();

	return 0;
}
