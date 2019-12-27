#include <iostream>

using  namespace std;

int main() {

	int num, b;
	char v;
	int i = 1;
	int ans = 1;


	cin >> num >> v;

	if (v == '!') {
		while (i <= num) {
			ans = ans * i;
			i++;
		}
		cout << ans << endl;
	}
	else {
		cout << "Факториал!" << endl;
	}

	system("pause");
	return 0;
}