#include <iostream>

int main() {
	const unsigned int ROWS = 4, COLS = 3;
	char keypad[ROWS][COLS] = {
		'1', '2', '3',
		'4', '5', '6',
		'7', '8', '9',
		'*', '0', '#',
	};

	bool rowOn[ROWS];
	for (unsigned int i = 0; i < ROWS; i++)
		std::cin >> rowOn[i];

	bool colOn[COLS];
	for (unsigned int i = 0; i < COLS; i++)
		std::cin >> colOn[i];

	bool somethingPressed = false;
	for (unsigned int row = 0; row < ROWS; row++) {
		for (unsigned int col = 0; col < COLS; col++) {
			if (rowOn[row] && colOn[col]) {
				std::cout << keypad[row][col] << ' ';
				somethingPressed = true;
			}
		}
	}

	if (!somethingPressed)
		std::cout << "Nothing pressed";

	std::cout << std::endl;

	return 0;
}
