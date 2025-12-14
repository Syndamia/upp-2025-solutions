#include <iostream>

int main() {
	const unsigned LINE_SIZE = 1024;

	char line[LINE_SIZE];
	std::cin.getline(line, LINE_SIZE);

	// char е 8 битово, което означава че има 2^^8 = 256
	// на брой различни възможни стойности.
	// Знаем, че всяка буква всъщност е едно число, затова
	// можем директно да го използваме като индекс.

	bool encountered[256] = { 0 };
	for (unsigned i = 0; line[i] != '\0'; i++)
		encountered[line[i]] = true;

	// Всички малки букви са отместени с 32 спрямо главните.
	// Тоест, главна буква + 32 = съответната малка буква

	bool isPangram = true;
	for (char ch = 'A'; isPangram && ch <= 'Z'; ch++)
		isPangram = encountered[ch] || encountered[ch + 32];

	if (isPangram)
		std::cout << "Pangram" << std::endl;
	else
		std::cout << "Not a pangram" << std::endl;

	return 0;
}
