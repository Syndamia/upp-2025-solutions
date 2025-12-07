#include <iostream>

void resizeArray(int*& arr, unsigned int& size) {
	int* newArr = new int[size * 2];
	for (unsigned int i = 0; i < size; i++)
		newArr[i] = arr[i];

	delete[] arr;
	arr = newArr;
	size *= 2;
}

int main() {
	unsigned int countA = 0, sizeA = 4, countB = 0, sizeB = 4;
	int* arrA = new int[sizeA], *arrB = new int[sizeB];

	bool even = true;
	int temp;
	std::cin >> temp;

	while (temp > 0) {
		if (even) {
			arrA[countA++] = temp;
			if (countA >= sizeA)
				resizeArray(arrA, sizeA);
		}
		else {
			arrB[countB++] = temp;
			if (countB >= sizeB)
				resizeArray(arrB, sizeB);
		}

		even = !even;
		std::cin >> temp;
	}

	unsigned int count = (countA > countB) ? countA : countB;
	for (unsigned int i = 0; i < count; i++) {
		if (i < countB)
			std::cout << arrB[countB - 1 - i] << ' ';
		if (i < countA)
			std::cout << arrA[i] << ' ';
	}
	std::cout << std::endl;

	delete[] arrA;
	delete[] arrB;

	return 0;
}
