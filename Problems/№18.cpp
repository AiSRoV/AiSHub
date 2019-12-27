#include <iostream>
#include <ctime>

using namespace std;

int main() {

	int a[20];
	int min = 100, max = -100;

	srand(time(NULL));

	for (int i = 0; i < 20; i++) {
		a[i] = rand() % 201 - 100;
	}

	for (int i = 0; i < 20; i++) {
		if (min > a[i]) min = a[i];
		if (max < a[i]) max = a[i];
		cout << a[i] << ' ';
	}

	cout << endl << "Минимум " << min << ' ' << "максимум " << max << endl;

	return 0;
}