#include <iostream>

const unsigned MAX_BITS = 32;

void printBits(unsigned bits, unsigned i, char buffer[MAX_BITS]) {
	if (bits == 0) {
		buffer[i] = '\0';
		std::cout << buffer << std::endl;
	}
	else {
		buffer[i] = '0';
		printBits(bits - 1, i + 1, buffer);
		buffer[i] = '1';
		printBits(bits - 1, i + 1, buffer);
	}
}

int main() {
	unsigned bits;
	std::cin >> bits;

	char buffer[MAX_BITS];
	printBits(bits, 0, buffer);

	return 0;
}
