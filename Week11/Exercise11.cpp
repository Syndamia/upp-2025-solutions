#include <iostream>

bool streq(const char* str1, const char* str2) {
	while (*str1 != '\0' && *str2 != '\0') {
		if (*str1++ != *str2++)
			return false;
	}
	return true;
}

unsigned strlen(const char* str) {
	unsigned len = 0;
	while (*str++ != '\0')
		len++;
	return len;
}

int main() {
	const unsigned MAX_LINE_LENGTH = 1024;
	char first[MAX_LINE_LENGTH], second[MAX_LINE_LENGTH];

	std::cin.getline(first, MAX_LINE_LENGTH);
	std::cin.getline(second, MAX_LINE_LENGTH);

	// Как премахваме букви? Най-лесния начин е просто да ги презапишем.
	// Все едно отместваме частта от низа след буквата, така че да се
	// застъпи с това, което премахваме.
	//
	// Например, ако в "abcde" искаме да премахнем c, тогава просто
	// на позицията на c ще запишем d, на позицията на d ще запишем е
	// и на позицията на e ще запишем терминираща нула.

	unsigned secondLen = strlen(second);

	for (unsigned readIndex = 0, writeIndex = 0; first[readIndex] != '\0'; readIndex++, writeIndex++) {
		if (streq(first + readIndex, second))
			readIndex += secondLen;

		if (readIndex != writeIndex) {
			first[writeIndex] = first[readIndex];
			first[writeIndex + 1] = '\0';
		}
	}

	std::cout << first << std::endl;

	return 0;
}
