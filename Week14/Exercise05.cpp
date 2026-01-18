#include <iostream>

void getSubnumbers(unsigned int x, unsigned int& first, unsigned int& second, unsigned int& third) {
	first  = (x & (0b11111111111 << 21)) >> 21;
	second = (x & (0b11111111111 << 10)) >> 10;
	third  =  x &  0b1111111111;
}

int main() {
	unsigned int a, b;
	std::cin >> a >> b;

	unsigned int aFirst, aSecond, aThird;
	getSubnumbers(a, aFirst, aSecond, aThird);

	unsigned int bFirst, bSecond, bThird;
	getSubnumbers(b, bFirst, bSecond, bThird);

	char op;
	std::cin >> op;
	switch (op) {
		case '+':
			aFirst += bFirst;
			aSecond += bSecond;
			aThird += bThird;
			break;

		case '-':
			aFirst -= bFirst;
			aSecond -= bSecond;
			aThird -= bThird;
			break;

		case '*':
			aFirst *= bFirst;
			aSecond *= bSecond;
			aThird *= bThird;
			break;

		case '/':
			aFirst /= bFirst;
			aSecond /= bSecond;
			aThird /= bThird;
			break;
	}

	aFirst  %= 0b100000000000;
	aSecond %= 0b100000000000;
	aThird  %= 0b10000000000;

	std::cout << aFirst << ' ' << aSecond << ' ' << aThird << std::endl;

	return 0;
}
