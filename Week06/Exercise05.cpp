#include <iostream>

int main() {
	double x, y;
	std::cin >> x >> y;

	bool below_top_left_corner = (x > -4) && (y < 2);
	bool above_bottom_left_corner = (x > -4) && (y > -1);

	/* Уравнение на правата:
	 * y = mx + b
	 * Където m е наклон.
	 * m = (промяна в y) / (промяна в x)
	 * ОБАЧЕ знакът на m е отрицателен, когато наклонът е на дясно (от горе в ляво до долу в дясно)
	 * Правата "отива нагоре" с 1 и на дясно с 1, следвателно m = 1/1 = 1
	 * Когато x = 0, тогава y = 1, следователно b = 1
	 *
	 * Уравнението за нашата права е:
	 * y = x + 1
	 *
	 * Точка е над правата, когато y > x + 1 (и под правата когато y < x + 1)
	 */
	bool is_above_line = y > x + 1;

	if (below_top_left_corner && above_bottom_left_corner && is_above_line)
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Outside" << std::endl;

	return 0;
}
