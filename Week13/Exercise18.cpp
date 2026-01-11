#include <iostream>

unsigned digitOccur(unsigned num, unsigned digit) {
	if (num == 0)
		return 0;
	else
		return (num % 10 == digit) + digitOccur(num / 10, digit);
}

int main() {
	unsigned num, digit;
	std::cin >> num >> digit;

	std::cout << digitOccur(num, digit) << std::endl;

	return 0;
}
