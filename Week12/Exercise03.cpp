#include <iostream>

void printRepeat(char x, unsigned int repeat) {
	while (repeat-- > 0)
		std::cout << x;
}

char* getField(unsigned &allocated, unsigned &size);

int main() {
	unsigned int allocated1, size1;
	char* field1 = getField(allocated1, size1);

	unsigned int allocated2, size2;
	char* field2 = getField(allocated2, size2);

	int columns;
	std::cin >> columns;

	columns = columns - size1 - size2;

	if (columns <= 0) {
		std::cout << field1 << field2 << std::endl;
	}
	else {
		unsigned int sideSpaces = columns / 3, middleSpaces = columns / 3;
		if (columns % 3 == 1)
			middleSpaces++;
		else if (columns % 3 == 2)
			sideSpaces++;

		// Алтернативно може да създадем низ с дадения брой шпации и
		// да изкараме него, вместо да принтираме шпациите директно.

		printRepeat(' ', sideSpaces);
		std::cout << field1;
		printRepeat(' ', middleSpaces);
		std::cout << field2;
		printRepeat(' ', sideSpaces);
		std::cout << std::endl;
	}

	delete[] field1;
	delete[] field2;

	return 0;
}

// Тази функция е почти същата като getLine от задача 2, само че
// разделителя (разделителите) между малко се различава.
// По-точно, позволява да имаме произволен брой шпации между полетата
// във входа, без това да влияе върху резултата.
char* getField(unsigned &allocated, unsigned &size) {
	allocated = 8;
	size = 0;

	char* input = new char[allocated];

	char curr;
	std::cin.get(curr);
	while ((curr != ' ' || size == 0) && curr != '\n') {
		if (curr != ' ')
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
