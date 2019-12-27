#include <iostream>

using  namespace std;

int main() {

	int num, z, b, x;

	z = 1;
	x = 2;
	b = 2;

	cin >> num;

	if (num == 0) {
		cout << 0 << endl;
	}
	else {
		if (x <= num) {
			while (x <= num) {
				x = x * b;
				z++;
			}
		}
		else {
			cout << 1 << endl;
		}
		cout << z << endl;
	}

	system("pause");
	return 0;
}