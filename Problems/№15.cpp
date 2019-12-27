#include <iostream>


using namespace std;


void  func(int* r, int num, int s) {
	for (int i = 0; i < s; i++) if (num < *(r + i)) swap(num, r[i]);
	if (s < 5)  r[s] = num;
}


void out(int* r, int num) {
	for (num; num >= 0; num--) cout << *(r + num) << ' ';
	cout << endl;
}


int main() {
	int a, temp;
	int b[5];

	cout << "¬вдете длину массива: ";

	cin >> a;

	cout << "¬ведите массив:" << endl;

	for (int i = 0; i < a; i++) {
		cin >> temp;
		if (i == 0) b[0] = temp;
		else func(b, temp, (i > 5 ? 5 : i));
		out(b, (i > 4 ? 4 : i));
	}

	return 0;
}