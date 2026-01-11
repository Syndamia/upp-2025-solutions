#include <iostream>

double sum(double totalsum, const double* elems, unsigned size) {
	if (size == 0)
		return totalsum;
	else
		return sum(totalsum + *elems, elems + 1, size - 1);
}

int main() {
	unsigned size;
	std::cin >> size;

	double* arr = new double[size];
	for (unsigned i = 0; i < size; ++i)
		std::cin >> arr[i];

	std::cout << sum(0.0, arr, size) << std::endl;

	free(arr);

	return 0;
}
