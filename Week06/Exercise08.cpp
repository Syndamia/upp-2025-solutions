#include <iostream>

int main() {
	const double PI = 3.14159;

	double x, y;
	std::cin >> x >> y;

	/* Уравнение на окръжността:
	 * (x - a) ^^ 2 + (y - b) ^^ 2 = r ^^ 2
	 * където ^^ представлява операцията степенуване (само за обяснението, няма такава в C++),
	 * a и b са координати на центъра на окръжността,
	 * r е радиуса на окръжността.
	 *
	 * Очевидно, ако имаме <, тогава сме в кръга, и ако имаме >, сме извън.
	 */

	const double BLUE_X = 1, BLUE_Y = 0, BLUE_R = 3;
	bool inside_blue = (x - BLUE_X) * (x - BLUE_X) + (y - BLUE_Y) * (y - BLUE_Y) < BLUE_R * BLUE_R;

	const double RED_X = 0, RED_Y = -1, RED_R = 3;
	bool outside_red = (x - RED_X) * (x - RED_X) + (y - RED_Y) * (y - RED_Y) > RED_R * RED_R;

	if (inside_blue && outside_red)
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Outside" << std::endl;

	return 0;
}
