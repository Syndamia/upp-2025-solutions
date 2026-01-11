#include <iostream>

unsigned fib(unsigned n) {
	if (n <= 1)
		return n;
	else
		return fib(n - 1) + fib(n - 2);
}

void intertwinedFib(unsigned i, unsigned max) {
	if (i > max) {
		std::cout << std::endl;
	}
	else {
		if (i > 0)
			std::cout << ' ';
		std::cout << fib(i) << ' ' << fib(max - i);
		intertwinedFib(i + 1, max);
	}
}

int main() {
	unsigned n;
	std::cin >> n;

	intertwinedFib(0, n);

	return 0;
}
