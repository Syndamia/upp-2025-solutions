#include <iostream>

unsigned passwordGrade(const char* password) {
	unsigned charCount = 0;
	bool containsLetter = false, containsDigit = false, containsSpecial = false, noNeighbouring = true;

	while (*password != '\0') {
		if (('a' <= *password && *password <= 'z') ||
		    ('A' <= *password && *password <= 'Z'))
		{
			containsLetter = true;
		}
		else if ('0' <= *password && *password <= '9') {
			containsDigit = true;
		}
		else {
			containsSpecial = true;
		}

		if (password[0] == password[1]) {
			noNeighbouring = false;
		}

		charCount++;
		password++;
	}

	return (charCount >= 15) + containsLetter + containsDigit + containsSpecial + noNeighbouring;
}

int main() {
	unsigned allocated = 8, size = 0;
	char* password = new char[allocated];

	char curr;
	std::cin.get(curr);
	while (curr != '\n') {
		password[size++] = curr;
		std::cin.get(curr);

		// Реоразмеряване
		if (size >= allocated) {
			allocated *= 2;
			char* newSentenceArray = new char[allocated];

			for (unsigned i = 0; i < size; i++)
				newSentenceArray[i] = password[i];

			delete[] password;
			password = newSentenceArray;
		}
	}
	password[size] = '\0';

	std::cout << passwordGrade(password) << std::endl;

	delete[] password;

	return 0;
}
