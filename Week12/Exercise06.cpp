#include <iostream>

/* Менажиране на памет на текста */

// Заделяне на памет
void newText(char**& text, unsigned& size, unsigned& allocated) {
	size = 0;
	allocated = 8;
	text = new char*[allocated];
}

// Реоразмеряване
void enlargeText(char**& text, unsigned& size, unsigned& allocated) {
	allocated *= 2;
	char** largerText = new char*[allocated];

	for (unsigned i = 0; i < size; i++)
		largerText[i] = text[i];

	delete[] text;
	text = largerText;
}

// Освобождаване на памет
void deleteText(char**& text, unsigned& size) {
	for (unsigned i = 0; i < size; i++)
		delete[] text[i];
	delete[] text;
	text = nullptr;
}

/* Обсег */
//
// Тези функции наричам "консуматори", защото приемат указател към низ,
// който указател инкрементират.
//
// Тоест, ако указателя сочи към "1234Hello", след като го подадем на
// consumeUnsigned, ще сочи към "Hello" (и value ще бъде 1234).
//

bool isDigit(char x) {
	return '0' <= x && x <= '9';
}

bool consumeUnsigned(const char*& cmd, unsigned& value) {
	value = 0;
	bool consumedAnything = false;

	while (isDigit(*cmd) && *cmd != '\0') {
		value = value * 10 + (*cmd - '0');
		cmd++;
		consumedAnything = true;
	}

	return consumedAnything;
}

bool consumeLineAddress(const char*& cmd, unsigned current, unsigned lastLine, unsigned& address) {
	bool consumedAnything = false;

	if (*cmd == '.') {
		address = current;
		cmd++;
		consumedAnything = true;
	}
	else if (*cmd == '$') {
		address = lastLine;
		cmd++;
		consumedAnything = true;
	}
	else {
		consumedAnything = consumeUnsigned(cmd, address);

		// Ако не ни е подаден адрес
		if (address == 0) {
			address = current;
		}
		// Ако има числов адрес
		else {
			address--;
			if (address > lastLine)
				address = lastLine;
		}
	}

	return consumedAnything;
}

// Обработва подадения обсег, като връща индекси rangeStart и rangeEnd,
// т.е. автоматично превръща ред "5" на индекс 4.
void consumeLineRange(const char*& cmd, unsigned current, unsigned lastLine, unsigned& rangeStart, unsigned& rangeEnd) {
	bool consumedStart = consumeLineAddress(cmd, current, lastLine, rangeStart);

	if (*cmd == ',') {
		// Ако не въведем обсег, тогава обсега е текущия ред.
		// Но, ако въведем обсег за няколко реда, без да има
		// експлицитни начало и край (т.е. целия обсег е ","),
		// тогава това трябва да е същото като "1,$".
		if (!consumedStart)
			rangeStart = 0;

		cmd++;

		if (!consumeLineAddress(cmd, current, lastLine, rangeEnd))
			rangeEnd = lastLine;
	}
	else {
		rangeEnd = rangeStart;
	}
}

/* Команда */

void printCommand(char** text, unsigned& textLines, unsigned selected) {
	if (selected >= textLines)
		std::cout << "(null text)" << std::endl;
	else
		std::cout << text[selected] << std::endl;
}

void enumerateCommand(char** text, unsigned& textLines, unsigned selected) {
	if (selected >= textLines) {
		std::cout << "(null text)" << std::endl;
	}
	else {
		std::cout << (selected + 1) << ' ';
		printCommand(text, textLines, selected);
	}
}

void deleteCommand(char**& text, unsigned& textLines, unsigned selected) {
	if (textLines < 1)
		return;

	delete[] text[selected];

	// Отместваме всички редове под изтрития с една позиция нагоре
	if (textLines > 1) {
		for (unsigned l = selected; l < textLines - 1; l++)
			text[l] = text[l + 1];
	}

	text[--textLines] = nullptr;
}

char* cpystr(const char* str) {
	// Тази логика може да се изведе в strlen
	unsigned length = 0;
	while (str[length] != '\0')
		length++;

	char* copy = new char[length + 1];
	// <= length, за да копираме терминиращата нула
	for (unsigned i = 0; i <= length; i++)
		copy[i] = str[i];

	return copy;
}

void insertCommand(const char* argText, char**& text, unsigned& textLines, unsigned& textAllocated, unsigned selected) {
	if (textAllocated <= textLines + 1)
		enlargeText(text, textLines, textAllocated);

	// Да вмъкнем текст преди даден ред е същото, като да
	// измествим с един ред надолу всички редове от избрания до последния вкл.
	// и да променим реда на който индекс оригинално беше избрания.
	// Гаден случай: ако текста ни е празен, не трябва да правим преместването.
	if (textLines > 0) {
		for (unsigned i = textLines; i > selected; i--)
			text[i] = text[i - 1];
	}
	textLines++;

	text[selected] = cpystr(argText);
}

void appendCommand(const char* argText, char**& text, unsigned& textLines, unsigned& textAllocated, unsigned selected) {
	// Да добавиш текст след подаден ред е същото, като
	// да добавиш текст преди реда след подадения.
	// Гаден случай: ако текста ни е празен, трябва задължително да
	// вмъкнем на ред с индекс 0.
	insertCommand(argText, text, textLines, textAllocated, selected + (textLines > 0));
}

bool evaluateCommand(const char* cmd, char**& text, unsigned& textLines, unsigned& textAllocated, unsigned& current) {
	unsigned start, end;
	consumeLineRange(cmd, current, textLines - (textLines > 1), start, end);

	if (start > end) {
		std::cout << "Start line in range cannot be after end line!" << std::endl;
		return true;
	}

	for (unsigned selected = start; selected <= end; selected++) {
		switch (*cmd) {
			// Ако има само въведен обсег и няма въведена команда
			case '\0':
				current = selected;
				break;

			case 'p':
				printCommand(text, textLines, selected);
				break;

			case 'n':
				enumerateCommand(text, textLines, selected);
				break;

			case 'd':
				deleteCommand(text, textLines, selected);

				if (selected <= current && current > 0)
					current--;

				if (end > 0) {
					end--;
					// Тук се възползваме от факта, че (при unsigned int)
					// 0 - 1 = 4294967295
					// 4294967295 + 1 = 0
					selected--;
				}

				break;

			case 'i':
				insertCommand(cmd + 1, text, textLines, textAllocated, selected);
				current = selected;

				end++;
				selected++;
				break;

			case 'a':
				appendCommand(cmd + 1, text, textLines, textAllocated, selected);
				current = selected + (textLines > 1);

				end++;
				selected++;
				break;

			case 'q':
				return false;

			default:
				std::cout << "Unknown command " << *cmd << "!" << std::endl;
				return true;
		}
	}
	return true;
}

void getInput(char*& input, unsigned &allocated, unsigned &size);

int main() {
	unsigned textAllocated, textSize;
	char** text;
	newText(text, textSize, textAllocated);

	unsigned currentLine = 0;

	unsigned cmdAllocated = 0, cmdSize = 0;
	char* cmd;

	getInput(cmd, cmdAllocated, cmdSize);
	while (evaluateCommand(cmd, text, textSize, textAllocated, currentLine)) {
		cmdSize = 0;
		getInput(cmd, cmdAllocated, cmdSize);
	}

	deleteText(text, textSize);
	delete[] cmd;

	return 0;
}

void getInput(char*& input, unsigned &allocated, unsigned &size) {
	if (allocated == 0) {
		allocated = 8;
		size = 0;

		input = new char[allocated];
	}

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
}
