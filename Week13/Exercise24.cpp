#include <iostream>

double ex(double x, unsigned i, unsigned n) {
	if (i == 0)
		return 1 + x / ex(x, i + 1, n);
	else if (i == 1)
		return 1 - x / ex(x, i + 1, n);
	else if (i == n)
		return i + x;
	else
		return i + x - i * x / ex(x, i + 1, n);
}

int main()
{
	double x;
	unsigned n;
	std::cin >> x >> n;

	std::cout << ex(x, 0, n) << std::endl;

	return 0;
}
