#include <iostream>

bool isDigit(char x) {
	return '0' <= x && x <= '9';
}

bool isLetter(char x) {
	return ('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z');
}

bool followsPattern(char letters[4]) {
	return isLetter(letters[0]) && isDigit(letters[1]) && isLetter(letters[2]) && isDigit(letters[3]);
}

int main() {
	const unsigned int SIZE = 12;
	char input[SIZE];
	for (unsigned int i = 0; i < SIZE; i++)
		std::cin >> input[i];

	for (unsigned int i = 0; i < SIZE; i += 4) {
		if (!followsPattern(input)) {
			std::cout << "Does not follow pattern" << std::endl;
			return 0;
		}
	}

	std::cout << "Follows pattern" << std::endl;
	return 0;
}
