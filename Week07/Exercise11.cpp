#include <iostream>

bool isPrime(unsigned int x) {
	for (unsigned int div = 2; div < x; div++) {
		if (x % div == 0)
			return false;
	}
	return x > 1;
}

int main() {
	unsigned int a, b;
	std::cin >> a >> b;

	unsigned int count = 0;
	while (a <= b) {
		count += isPrime(a);
		a++;
	}

	std::cout << count << std::endl;

	return 0;
}
