#include <iostream>
#include <iomanip>
#include <cmath>

double a, b, c;
double des;
double desk;
double x1, x2;
double x;

int main() {
	setlocale(LC_ALL, "Russian");

	std::cin >> a >> b >> c;

	if (a != 0 && b != 0 && c != 0) {
		des = b * b - 4 * a * c;
		if (des < 0) {
			std::cout << "Корней нет" << std::endl;
		}
		else {
			desk = sqrt(des);
			x1 = (-b + desk) / (2 * a);
			x2 = (-b - desk) / (2 * a);
			std::cout << x1 << ' ' << x2 << std::endl;
		}
	}

	if (a = 0 && b = 0) {
		std::cout << "Корней нет" << std::endl;
	}

	if (a = 0 && c = 0) {
		std::cout << "0" << std::endl;
	}

	if (b = 0 && c = 0) {
		std::cout << "0" << std::endl;
	}

	if (a = 0) {
		x = -c / b;
		std::cout << x << std::endl;
	}

	if (b = 0) {
		x = sqrt(-c / a);
		std::cout << x << std::endl;
	}

	if (c = 0) {
		x1 = 0;
		x2 = -b / a;
		std::cout << x1 << ' ' << x2 << std::endl;
	}



	system ("pause");
	return 0;
}