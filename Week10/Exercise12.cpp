#include <iostream>

int main() {
	unsigned int count = 0, allocated = 4;
	int* indecies = new int[allocated];
	double* values = new double[allocated];

	int index;
	std::cin >> index;
	while (index >= 0) {
		indecies[count] = index;
		std::cin >> values[count++];

		if (count >= allocated) {
			allocated *= 2;
			int* newIndecies = new int[allocated];
			double* newValues = new double[allocated];

			for (unsigned int i = 0; i < count; i++) {
				newIndecies[i] = indecies[i];
				newValues[i] = values[i];
			}

			delete[] indecies;
			delete[] values;

			indecies = newIndecies;
			values = newValues;
		}

		std::cin >> index;
	}

	std::cin >> index;
	bool printed = false;

	for (unsigned int i = 0; i < count; i++) {
		if (indecies[i] == index) {
			std::cout << values[i] << std::endl;
			printed = true;
			break;
		}
	}

	if (!printed)
		std::cout << 0 << std::endl;

	delete[] indecies;
	delete[] values;

	return 0;
}
