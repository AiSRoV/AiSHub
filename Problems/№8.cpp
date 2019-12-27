#include <iostream>
#include <iomanip>
#include <cmath>

int main() {

	double a, b, z;
	char c;

	std::cin >> a >> c >> b;

	switch (c) {
	case '/':
		if (b == 0) {
			std::cout << "На 0 не делят" << std::endl;
		}
		else {
			std::cout << a / b << std::endl;
		}
		break;
	case '-':
		std::cout << a - b << std::endl;

	case '+':
		std::cout << a + b << std::endl;
		break;
	case '*':
		std::cout << a * b << std::endl;
		break;
	case '^':
		z = a;
		if (b > 0) {
			while (b > 1) {
				a = a * z;
				b--;
			}
			std::cout << a << std::endl;
		}
		else {
			if (b < 0) {
				b = b * -1;
				while (b > 1) {
					a = a * z;
					b--;
				}
				std::cout << 1 / a << std::endl;
			}
			else {
				std::cout << 1 << std::endl;
			}
		}
		break;
	default:
		std::cout << "Error!" << std::endl;
	}

	system("pause");
	return 0;
}