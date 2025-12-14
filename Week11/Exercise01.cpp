#include <iostream>

int main() {
	const unsigned NAME_LENGTH = 20;

	// 20 букви за името и 1 буква за терминиращата нула
	char name[NAME_LENGTH + 1];
	std::cin.getline(name, NAME_LENGTH + 1);

	std::cout << "Hello, " << name << "!" << std::endl;

	return 0;
}
