#include <iostream>

int main() {
	unsigned int x;
	std::cin >> x;

	unsigned first  = (x & (0b11111111 << 24)) >> 24;
	unsigned second = (x & (0b11111111 << 16)) >> 16;
	unsigned third  = (x & (0b11111111 << 8))  >> 8;
	unsigned fourth =  x &  0b11111111;

	std::cout << first << ' ' << second << ' ' << third << ' ' << fourth << std::endl;

	return 0;
}
