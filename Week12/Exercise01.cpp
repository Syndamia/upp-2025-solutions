#include <iostream>

bool isLetter(char x) {
	return ('A' <= x && x <= 'Z') || ('a' <= x && x <= 'z');
}

// Отмества един път на дясно всяка буква по шифъра на цезар.
// Тоест, а става b, b става c, ..., z става a
void caesarShift(char* str, unsigned int size) {
	for (unsigned int i = 0; i < size; i++) {
		if (isLetter(str[i])) {
			str[i]++;

			// Тази логика може да се пренапише с модулно деление
			if ('z' < str[i])
				str[i] = 'a';
			else if ('Z' < str[i] && str[i] < 'a')
				str[i] = 'A';
		}
	}
}

char toLower(char x) {
	if ('A' <= x && x <= 'Z')
		return x + ('a' - 'A');
	return x;
}

// Дали първия низ започва с цялото съдържание на втория низ,
// игнорирайки дали букви са главни или малки.
bool isSubstr(const char* str, unsigned int size, const char* substr, unsigned int subsize) {
	if (size < subsize)
		return false;

	for (unsigned int i = 0; i < subsize; i++)
		if (toLower(str[i]) != toLower(substr[i]))
			return false;

	return !isLetter(str[subsize]);
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

// Ще зачетем едно съобщение за дешифрирано ако съдържа една от често-срещаните думи.
// На теория може би е възможно шифрирано съобщение да съдържа някоя от тях, но това е
// извън обхвата на задачата.
//
// Алгоритъма е следния: проверяваме дали съобщението е дешифрирано, ако не е,
// отместваме всяка буква с една позиция (a -> b, b -> c, ..., z -> a) и пробваме пак.
bool bruteforceCaesar(char* text, unsigned int size) {
	for (unsigned int shift = 0; shift < 26; shift++) {
		for (unsigned int i = 0; i < size; i++) {
			// По-добра реализация е да обикалеме масив от низове.
			// Обаче, така ми се стурва по-лесно за разбиране.
			if (isSubstr(text + i, size - i, "the", 3) ||
			    isSubstr(text + i, size - i, "be",  2) ||
			    isSubstr(text + i, size - i, "to",  2) ||
			    isSubstr(text + i, size - i, "of",  2) ||
			    isSubstr(text + i, size - i, "and", 3))
			{
				return true;
			}
		}

		caesarShift(text, size);
	}
	return false;
}

int main() {
	unsigned int allocated, size;
	char* text = getInput(allocated, size);

	if (bruteforceCaesar(text, size)) {
		std::cout << text << std::endl;
	}
	else {
		std::cout << "Couldn't bruteforce the message!" << std::endl;
	}

	delete[] text;

	return 0;
}
