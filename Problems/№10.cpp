#include <iostream>

using  namespace std;

int main() {

	double otr, num, st, z, b;
	char v;

	cin >> num >> v >> st;

	b = num;
	otr = num;
	z = 1;

	if (st > 0) {
		if (v == '^') {
			while (z < st) {
				num = num * b;
				z++;
			}
		}
		else {
			cout << "Мы тут в степень возводим, вообще-то" << endl;
		}
	}
	else {
		if (st < 0) {
			while (z < (st * -1)) {
				otr = otr * b;
				z++;
			}
			num = 1 / otr;
		}
		else {
			if (st == 0) {
				num = 1;
			}
		}
	}

	cout << num << endl;

	system("pause");
	return 0;
}