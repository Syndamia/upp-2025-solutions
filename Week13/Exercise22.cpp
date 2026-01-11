#include <iostream>
#include <cmath>

double agm(double an, double gn, unsigned i) {
	if (i == 0)
		return (an + gn) / 2.0;
	else
		return agm((an + gn) / 2.0, sqrt(an * gn), i - 1);
}

int main()
{
	double a, b;
	unsigned n;
	std::cin >> a >> b >> n;

	std::cout << agm(a, b, n) << std::endl;

	return 0;
}
