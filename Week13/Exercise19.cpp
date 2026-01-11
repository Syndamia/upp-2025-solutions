#include <iostream>

unsigned binom(unsigned n, unsigned k) {
	if (k == 0 || n == k)
		return 1;
	return binom(n - 1, k - 1) + binom(n - 1, k);
}

int main() {
	unsigned n, k;
	std::cin >> n >> k;

	std::cout << binom(n, k) << std::endl;

	return 0;
}
