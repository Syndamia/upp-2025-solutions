#include <iostream>

unsigned fieldsCount(const char* str) {
	// Едно поле не съдържа шпации, което реално означава, че
	// всяко поле ще бъде заобиколено от шпации (с леко изключение
	// на първото и последното поле).
	//
	// В такъв случай, можем да кажем, че началото на поле се "маркира"
	// с първата не-шпация след редица от шпации. Тоест, ако текущия
	// знак не е шпация, достатъчно е да погледнем предходния знак, за да
	// разберем дали сме започнали поле или сме по средата на поле.
	//
	// И за нашата задача, остава само да преборим тези начала, което е
	// същото като броя полета. Допълнително, ако инициализираме
	// предходната буква да е шпация, тогава винаги ще преборим първото
	// поле.
	//
	// Да, задачата може да се реши без запазването на целия низ.

	unsigned count = 0;

	char prev = ' ';
	char curr = *(str++);

	while (curr != '\0') {
		count += prev == ' ' && curr != ' ';

		prev = curr;
		curr = *(str++);
	}

	return count;
}

int main() {
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

	std::cout << fieldsCount(sentence) << std::endl;

	delete[] sentence;

	return 0;
}
