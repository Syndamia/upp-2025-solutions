#include <iostream>
#include <cmath>

double eccentricAnomaly(double M, double e, unsigned depth) {
	if (depth == 0)
		return M;
	return M + e * sin(eccentricAnomaly(M, e, depth - 1));
}

int main()
{
	double M, e;
	unsigned depth;
	std::cin >> M >> e >> depth;

	std::cout << eccentricAnomaly(M, e, depth) << std::endl;

	return 0;
}
