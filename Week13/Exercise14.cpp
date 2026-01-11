#include <iostream>

const unsigned LEHMER_a = 16807;
const unsigned LEHMER_m = ((unsigned long)1 << 31) - 1;

void lehmerPrint(unsigned i, unsigned N, unsigned Xk) {
	if (i >= N) {
		std::cout << Xk << std::endl;
		return;
	}

	if (i > 0)
		std::cout << Xk << ' ';

	lehmerPrint(i + 1, N, (LEHMER_a * Xk) % LEHMER_m);
}

int main()
{
	unsigned seed, N;
	std::cin >> seed >> N;

	lehmerPrint(0, N, seed);

	return 0;
}
