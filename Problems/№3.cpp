#include <iostream>
#include <iomanip>



int main() {
	setlocale(LC_ALL, "Russian");

	{
		int a, b;
		std::cout << "������� a" << std::endl;
		std::cin >> a;
		std::cout << "������� b" << std::endl;
		std::cin >> b;
		std::cout << a + b << std::endl;
		std::cout << a - b << std::endl;
		std::cout << a * b << std::endl;
		std::cout << a / b << std::endl;
	}

	{
		double a, b;
		std::cout << "������� a" << std::endl;
		std::cin >> a;
		std::cout << "������� b" << std::endl;
		std::cin >> b;
		std::cout << a + b << std::endl;
		std::cout << a - b << std::endl;
		std::cout << a * b << std::endl;
		std::cout << a / b << std::endl;
	}

	{
		int a;
		double b;
		std::cout << "������� a" << std::endl;
		std::cin >> a;
		std::cout << "������� b" << std::endl;
		std::cin >> b;
		std::cout << a + b << std::endl;
		std::cout << a - b << std::endl;
		std::cout << a * b << std::endl;
		std::cout << a / b << std::endl;
	}

	{
		int a;
		double b;
		std::cout << "������� a" << std::endl;
		std::cin >> a;
		std::cout << "������� b" << std::endl;
		std::cin >> b;
		std::cout << a + b << std::endl;
		std::cout << a - b << std::endl;
		std::cout << a * b << std::endl;
		std::cout << a / b << std::endl;
	}
	
	system ("pause");
	return 0;
}