#include <iostream>

unsigned fib(unsigned x) {
	if (x <= 1)
		return x;
	else
		return fib(x - 1) + fib(x - 2);
}

int main() {
	unsigned n;
	std::cin >> n;

	std::cout << fib(n) << std::endl;

	return 0;
}
