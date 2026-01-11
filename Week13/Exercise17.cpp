#include <iostream>
#include <cstring>

bool isPalindrome(unsigned left, unsigned right, const char* str) {
	if (left >= right)
		return true;
	else if (str[left] != str[right])
		return false;
	else
		return isPalindrome(left + 1, right - 1, str);
}

int main() {
	const unsigned LINE_LEN = 1024;

	char line[LINE_LEN];
	std::cin.getline(line, LINE_LEN);

	if (isPalindrome(0, strlen(line) - 1, line))
		std::cout << "Is a palindrome" << std::endl;
	else
		std::cout << "Not a palindrome" << std::endl;

	return 0;
}
