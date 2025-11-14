#include <iostream>

void calc(float number, double &half, int* integer) {
	half = number / 2.0;
	*integer = (int)number;
}

int main() {
	float input;
	std::cin >> input;

	double a;
	int b;
	calc(input, a, &b);

	std::cout << a << ' ' << b << std::endl;

	return 0;
}
