#include <iostream>

double average(int* arr, unsigned int size) {
	double sum = 0;
	for (unsigned int i = 0; i < size; i++)
		sum += arr[i];
	return sum / size;
}

int main() {
	unsigned int n;
	std::cin >> n;
	n *= 2;

	int* nums = new int[n];
	for (unsigned int i = 0; i < n; i++)
		std::cin >> nums[i];

	std::cout << average(nums, n) << std::endl;
	delete[] nums;
	return 0;
}
