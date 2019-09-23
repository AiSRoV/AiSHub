#include <iostream>
#include <iomanip>

int a, b, c;

int main() {
	setlocale(LC_ALL, "Russian");

	std::cin >> a >> b;

	c = a;
	a = b;
	b = c;

	std::cout << a << ' ' << b << std::endl;

	if (b > a) {
		a = b - a;
		b = b - a;
		a = b + a;
	} else {
		b = b - a;
		a = b - a;
		b = b + a;
	}

	std::cout << a << ' ' << b << std::endl;

	system ("pause");
	return 0;
}