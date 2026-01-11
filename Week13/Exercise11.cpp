#include <iostream>

void threeChildren(unsigned a, unsigned b, unsigned c, unsigned prod) {
	if (a * b * c == prod) {
		std::cout << a << ' ' << b << ' ' << c << std::endl;
		return;
	}

	if (b + 1 < c - 1)
		threeChildren(a, b + 1, c - 1, prod);
	if (b + 1 < c - 2)
		threeChildren(a + 1, b + 1, c - 2, prod);
}

void threeChildren(unsigned sum, unsigned prod) {
	threeChildren(1, 1, sum - 2, prod);
}

int main() {
	unsigned sum, prod;
	std::cin >> sum >> prod;

	threeChildren(sum, prod);

	return 0;
}
