#include <iostream>

using  namespace std;

int main() {

	int num, z;

	cin >> num;

	for (int i = 1; i < (num + 1); i++) {
		if ((num % i) == 0) {
			z++;
		}
	}

	if (z == 2) {
		cout << "Простое" << endl;
	}
	else {
		cout << "Составное" << endl;
	}

	system("pause");
	return 0;
}