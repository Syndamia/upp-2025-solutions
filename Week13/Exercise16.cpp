#include <iostream>

unsigned gcd(unsigned a, unsigned b) {
	if (a == b)
		return a;
	else if (a < b)
		return gcd(b, a);
	else
		return gcd(a - b, b);
}

int main() {
	unsigned a, b;
	std::cin >> a >> b;

	std::cout << gcd(a, b) << std::endl;

	return 0;
}
