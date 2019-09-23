#include <iostream>
#include <iomanip>

double const g = 9.8;
double x, v, t;
double vtf;
double x(t);

int main() {
	setlocale(LC_ALL, "Russian");

	std::cout << "¬ведите x, v и t:" << std::endl;
	std::cin >> x >> v >> t;

	vtf = (a * t * t) / 2;

	x(t) = (v * t) + x - vtf;

	std::cout << vtf << std::endl;

	system ("pause");
	return 0;
}