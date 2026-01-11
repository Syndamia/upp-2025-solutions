#include <iostream>

void line(unsigned n) {
	if (n == 0) {
		std::cout << std::endl;
	}
	else {
		std::cout << '+';
		line(n - 1);
	}
}

/* Два начина по които да имплементираме изкарването на "стълбите" */

void stairs1(unsigned i, unsigned max) {
	if (i <= max) {
		line(i);
		stairs1(i + 1, max);
	}
}

void stairs2(unsigned n) {
	if (n > 0) {
		stairs2(n - 1);
		line(n);
	}
}

int main() {
	unsigned n;
	std::cin >> n;

	// stairs1(1, n);
	stairs2(n);

	return 0;
}
