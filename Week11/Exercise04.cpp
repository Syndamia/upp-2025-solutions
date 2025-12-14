#include <iostream>

int main() {
	char prev = '\0', curr = prev;
	std::cin.get(curr);

	// Всеки ред се бележи с \n накрая. Ако имаме празен ред,
	// то целия ред ще съдържа само \n.
	// Тоест, ако имаме ред с текст, и директно след него "празен"
	// ред, то ще имаме две \n в последователност.

	unsigned count = 0;
	while (prev != '\n' || curr != '\n') {
		count += curr == '\n';

		prev = curr;
		std::cin.get(curr);
	}

	std::cout << count << std::endl;

	return 0;
}
