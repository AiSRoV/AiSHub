#include <iostream>
#include <string>

using namespace std;

int main() {

	int N;

	cout << "¬ведите длину массива: ";
	cin >> N;

	int a[N];
	cout << "¬ведите массив:" << endl;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	cout << endl;

	for (int i = 0; i < N; i++) {
		int min = a[i];
		for (int j = i; j < N; j++) {
			if (a[j] < min) {
				a[i] = a[j];
				a[j] = min;
				min = a[i];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << a[i] << ' ';
	}

	return 0;
}