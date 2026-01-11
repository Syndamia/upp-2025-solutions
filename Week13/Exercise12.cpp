#include <iostream>

unsigned max(unsigned a, unsigned b) {
	return a > b ? a : b;
}

unsigned longestIncreasing(int* nums, unsigned size, unsigned current) {
	if (size <= 1)
		return current + size;

	if (nums[0] < nums[1])
		return longestIncreasing(nums + 1, size - 1, current + 1);
	else
		return max(current + 1, longestIncreasing(nums + 1, size - 1, 0));
}

unsigned longestIncreasing(int* nums, unsigned size) {
	return longestIncreasing(nums, size, 0);
}

int main() {
	unsigned N;
	std::cin >> N;

	int* nums = new int[N];
	for (unsigned i = 0; i < N; ++i)
		std::cin >> nums[i];

	std::cout << longestIncreasing(nums, N) << std::endl;

	delete[] nums;

	return 0;
}
