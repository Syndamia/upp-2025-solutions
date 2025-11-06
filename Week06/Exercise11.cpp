#include <iostream>

int main() {
	const double PI = 3.14159;

	double x, y;
	std::cin >> x >> y;

	const double RED_X = 1.0, RED_Y = -0.5, RED_R = 2.0;
	bool outside_red = (x - RED_X) * (x - RED_X) + (y - RED_Y) * (y - RED_Y) > RED_R * RED_R;

	/* Представяме трите страни на триъгълника като наклонени прави.
	 */
	bool below_left_side = y < (5.0 / 3.0) * x + 3.833;
	bool below_right_side = y < (1.0 / 3.5) * -x + 2.857;
	bool above_bottom_side = y > (4.0 / 6.5) * x + 0.154;

	if (outside_red && below_left_side && below_right_side && above_bottom_side)
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Outside" << std::endl;

	return 0;
}
