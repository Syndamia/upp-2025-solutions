#include <iostream>

void sumavg(int a, int b, unsigned count, int& sum, double& avg) {
	if (a > b) {
		avg = (double)sum / count;
	}
	else {
		sum += a;
		sumavg(a + 1, b, count + 1, sum, avg);
	}
}

int main() {
	int a, b;
	std::cin >> a >> b;

	int sum = 0;
	double avg = 0.0;
	sumavg(a, b, 0, sum, avg);

	std::cout << sum << ' ' << avg << std::endl;

	return 0;
}
