#include <iostream>

int max(int maxval, const int* elems, unsigned size) {
	if (size == 0)
		return maxval;
	else
		return max(maxval > *elems ? maxval : *elems, elems + 1, size - 1);
}

int main() {
	unsigned size;
	std::cin >> size;

	int* arr = new int[size];
	for (unsigned i = 0; i < size; ++i)
		std::cin >> arr[i];

	std::cout << max(*arr, arr, size) << std::endl;

	free(arr);

	return 0;
}
