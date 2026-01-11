#include <iostream>

unsigned digitSum(unsigned x) {
	if (x == 0)
		return 0;
	else
		return x % 10 + digitSum(x / 10);
}

int main() {
	unsigned num;
	std::cin >> num;

	std::cout << digitSum(num) << std::endl;

	return 0;
}
