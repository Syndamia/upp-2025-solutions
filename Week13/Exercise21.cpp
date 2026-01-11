#include <iostream>
#include <cstring>

unsigned min(unsigned a, unsigned b, unsigned c) {
	if (a < b)
		return a < c ? a : c;
	return b < c ? b : c;
}

unsigned lev(const char* a, const char* b) {
	if (*b == '\0')
		return strlen(a);
	else if (*a == '\0')
		return strlen(b);
	else if (*a == *b)
		return lev(a + 1, b + 1);
	else
		return 1 + min(lev(a, b + 1), lev(a + 1, b), lev(a + 1, b + 1));
}

int main()
{
	const unsigned MAX_LEN = 1024;
	char line1[MAX_LEN], line2[MAX_LEN];

	std::cin.getline(line1, MAX_LEN);
	std::cin.getline(line2, MAX_LEN);

	std::cout << lev(line1, line2) << std::endl;

	return 0;
}
