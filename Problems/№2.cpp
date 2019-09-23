#include <iostream>
#include <iomanip>



int main() {
	setlocale(LC_ALL, "Russian");

	int a = 3;
	int b = 3.14;
	double c = 3;
	double d = 3.14;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;

	return 0;
}