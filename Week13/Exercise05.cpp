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

void hill(unsigned i, unsigned max) {
	if (i <= max) {
		line(i);
		hill(i + 1, max);
	}
	if (i < max)
		line(i);
}

int main() {
	unsigned n;
	std::cin >> n;

	hill(1, n);

	return 0;
}
