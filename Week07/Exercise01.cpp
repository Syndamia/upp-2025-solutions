#include <iostream>

// Името на функция трябва да бъде налично преди да използвате функцията.
// Това означава дефиницията (самата имплементация) и/или декларацията
// на функцията да бъде създадена преди нейната употреба.
bool evenAndPositive(int x) {
	return (x % 2 == 0) && x > 0;
}

int main() {
	int number;
	std::cin >> number;
	std::cout << evenAndPositive(number) << std::endl;

	return 0;
}
