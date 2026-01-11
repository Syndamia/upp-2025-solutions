#include <iostream>

const unsigned BOARD_SIZE = 4;

bool inrange(unsigned lower, unsigned x, unsigned upper) {
	return lower <= x && x <= upper;
}

bool isSolved(int board[BOARD_SIZE][BOARD_SIZE]) {
	unsigned firstSum = 0;
	for (unsigned row = 0; row < BOARD_SIZE; ++row) {
		unsigned rowSum = 0;

		for (unsigned col = 0; col < BOARD_SIZE; ++col) {
			// Валидно решение
			if (board[row][col] != 0 && board[row][col] != 1)
				return false;

			if (row == 0)
				firstSum += board[row][col];
			rowSum += board[row][col];

			// Последователност на 0ли и 1ци в реда
			if (inrange(1, col, BOARD_SIZE - 2) &&
				!inrange(1, board[row][col - 1] + board[row][col] + board[row][col + 1], 2))
				return false;

			// Последователност на 0ли и 1ци в колоната
			if (inrange(1, row, BOARD_SIZE - 2) &&
				!inrange(1, board[row - 1][col] + board[row][col] + board[row + 1][col], 2))
				return false;
		}

		// Еднакъв брой нули и единици на всеки ред
		if (firstSum != rowSum)
			return false;
	}

	for (unsigned col = 0; col < BOARD_SIZE; ++col) {
		unsigned colSum = 0;

		for (unsigned row = 0; row < BOARD_SIZE; ++row)
			colSum += board[row][col];

		// Еднакъв брой нули и единици на всяка колона (и това еднакво с всеки ред)
		if (firstSum != colSum)
			return false;
	}

	return true;
}

bool solve(unsigned index, int board[BOARD_SIZE][BOARD_SIZE]) {
	if (index == BOARD_SIZE * BOARD_SIZE)
		return isSolved(board);

	int& curr = board[index / BOARD_SIZE][index % BOARD_SIZE];

	if (curr != -1)
		return solve(index + 1, board);

	curr = 0;
	if (solve(index + 1, board))
		return true;

	curr = 1;
	if (solve(index + 1, board))
		return true;

	curr = -1;
	return false;
}

int main() {
	int board[BOARD_SIZE][BOARD_SIZE];

	for (unsigned row = 0; row < BOARD_SIZE; ++row)
		for (unsigned col = 0; col < BOARD_SIZE; ++col)
			std::cin >> board[row][col];

	solve(0, board);

	for (unsigned row = 0; row < BOARD_SIZE; ++row) {
		for (unsigned col = 0; col < BOARD_SIZE; ++col)
			std::cout << board[row][col] << ' ';
		std::cout << std::endl;
	}

	return 0;
}
