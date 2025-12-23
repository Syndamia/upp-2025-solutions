#include <iostream>

// Функциите тук "консумират" входния низ, тоест не просто
// превръщат буквите в някаква друга стойност, ами и инкрементират
// указателя, така че да се пропуснат обработените букви.

bool isDigit(char x) {
	return '0' <= x && x <= '9';
}

bool digitsUntil(const char*& str, char end) {
	bool hasAnyDigits = false;

	while (*str != '\0' && *str != end) {
		if (!isDigit(*str))
			return false;
		str++;
		hasAnyDigits = true;
	}

	return hasAnyDigits && *str == end;
}

bool isInteger(const char* text) {
	if (*text == '+' || *text == '-')
		text++;

	return digitsUntil(text, '\0');
}

bool isFloat(const char* text) {
	if (*text == '+' || *text == '-')
		text++;

	if (!digitsUntil(text, '.'))
		return false;
	text++;
	return digitsUntil(text, '\0');
}

bool isLetter(char x) {
	return ('A' <= x && x <= 'Z') || ('a' <= x && x <= 'z');
}

bool isWord(const char* text) {
	while (*text != '\0') {
		if (!isLetter(*text))
			return false;
		text++;
	}
	return true;
}

// В тази функция донякъде има един проблем:
// не проверяваме ако часа ни е 12-часов, дали часа е между 0 и 12 (вместо между 0 и 24).
// Обаче, по условие не ни е казано да проверяваме за това, затова изпускам проверката.
bool isTime(const char* text) {
	if ((text[0] == 'A' || text[0] == 'P') && text[1] == 'M')
		text += 2;

	if (!isDigit(*text) && '0' <= *text && *text <= '2')
		return false;
	text++;

	if (isDigit(*text))
		text++;

	if (*text != ':')
		return false;
	text++;

	if (!isDigit(*text) && '0' <= *text && *text <= '5')
		return false;
	text++;

	if (!isDigit(*text))
		return false;
	text++;

	if ((text[0] == 'A' || text[0] == 'P') && text[1] == 'M')
		text += 2;

	return *text == '\0';
}

bool isPercentage(char* text, unsigned int size) {
	if (!isDigit(*text))
		return false;

	if (text[size - 1] != '%')
		return false;

	text[size - 1] = '\0';

	return isInteger(text) || isFloat(text);
}

char* getInput(unsigned &allocated, unsigned &size);

int main() {
	unsigned int allocated, size;
	char* text = getInput(allocated, size);

	if (size == 0) {
		std::cout << "other" << std::endl;
	}
	else if (isInteger(text)) {
		std::cout << "integer" << std::endl;
	}
	else if (isFloat(text)) {
		std::cout << "float" << std::endl;
	}
	else if (isWord(text)) {
		std::cout << "word" << std::endl;
	}
	else if (isTime(text)) {
		std::cout << "time" << std::endl;
	}
	else if (isPercentage(text, size)) {
		std::cout << "percentage" << std::endl;
	}
	else {
		std::cout << "other" << std::endl;
	}

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
