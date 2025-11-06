#include <iostream>

int main() {
	const unsigned int SIZE = 10;
	int numbers[SIZE];

	for (int i = 0; i < SIZE; i++)
		std::cin >> numbers[i];

	bool found = false;
	for (int i = 0; i < SIZE && !found; i++) {
		for (int j = i + 1; j < SIZE && !found; j++) {
			for (int k = j + 1; k < SIZE && !found; k++) {
				found = numbers[i] + numbers[j] + numbers[k] == 0;
			}
		}
	}

	if (found)
		std::cout << "Exists" << std::endl;
	else
		std::cout << "Doesn't exist" << std::endl;

	return 0;
}
