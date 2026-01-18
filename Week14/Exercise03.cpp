#include <iostream>

int main() {
	unsigned int x;
	std::cin >> x;

	unsigned bitCounter = 0;
	while (x > 0) {
		bitCounter ^= x;
		x >>= 1;
	}

	std::cout << (bitCounter & 1) << std::endl;

	return 0;
}
