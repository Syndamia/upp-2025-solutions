#include <iostream>

int main() {
	unsigned int result = 0;

	for (unsigned int integer = 1; result == 0; integer++) {
		unsigned int square = integer * integer;
		if (square % 1000000 == 269696)
			result = integer;
	}

	std::cout << result << std::endl;

	return 0;
}
