#include <iostream>
#include <cstring>

/* Два начина по които да имплементираме обръщането на низа */

void revText1(unsigned left, unsigned right, char* str) {
	if (left < right) {
		char tmp = str[left];
		str[left] = str[right];
		str[right] = tmp;

		revText1(left + 1, right - 1, str);
	}
}

void revText2(char* left, char* right) {
	if (left < right) {
		char tmp = *left;
		*left = *right;
		*right = tmp;

		revText2(left + 1, right - 1);
	}
}

int main() {
	const unsigned MAX_LEN = 1024;

	char line[MAX_LEN];
	std::cin.getline(line, MAX_LEN);

	// revText1(0, strlen(line) - 1, line);
	revText2(line, line + strlen(line) - 1);

	std::cout << line << std::endl;

	return 0;
}
