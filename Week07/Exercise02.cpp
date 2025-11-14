#include <iostream>

// Това е пример за декларация на функция: просто описваме функцията
// как ще изглежда. Това ни позволява да сложим самата имплементация
// някъде другаде.
// Има специални механизми, чрез които самата дефиниция/имплементация
// се "свързва" навсякъде където я използваме. За това в бъдеще.
unsigned int fib(unsigned int n);

int main() {
	unsigned int num;
	std::cin >> num;
	std::cout << fib(num) << std::endl;

	return 0;
}

// Това е дефиницията/имплементацията на функцията.
unsigned int fib(unsigned int n) {
	unsigned int f0 = 0, f1 = 1;
	while (n > 0) {
		unsigned int temp = f0;
		f0 = f1;
		f1 += temp;

		n--;
	}
	return f0;
}
