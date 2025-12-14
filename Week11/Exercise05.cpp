#include <iostream>

int main() {
	const unsigned SIZE = 1024;

	char str[SIZE];
	std::cin.getline(str, SIZE, ':');
	double a, b;
	std::cin >> a >> b;

	for (unsigned i = 0; str[i] != '\0' && str[i+2] != '\0'; i++) {
		if (str[i]   == 's' &&
		    str[i+1] == 'u' &&
		    str[i+2] == 'm')
		{
			std::cout << (a + b) << ' ';
		}
		else if (str[i]   == 's' &&
		         str[i+1] == 'u' &&
		         str[i+2] == 'b')
		{
			std::cout << (a - b) << ' ';
		}
	}
	std::cout << std::endl;

	return 0;
}
