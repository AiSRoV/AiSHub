#include <iostream>
#include <ctime>

using namespace std;

int main() {

	int a[10][8] = {};
	int r, c, att = 5;
	srand(time(NULL));

	int* ptr = &a[0][0];
	int num = rand() % (10 * 8 - 1);
	*(ptr + num) = 1;

	while (att) {
		cout << "Осталось попыток: " << att << endl;
		cin >> r >> c;
		if ((r < 0) || (r > 9) || (c < 0) || (c > 7)) cout << "Вышли за рамки" << endl;
		else if (a[r][c] == -1) cout << "Не корректный ввод" << endl;
		else if (a[r][c] == 1) {
			cout << "Вы победили" << endl;
			break;
		}
		else {
			cout << "Не верный выбор" << endl;
			a[r][c] = -1;
			att--;
		}
	}
	if (!att) cout << "Вы проиграли" << endl;
	cout << "Загаданная ячейка: " << num / 8 << ' ' << num % 8 << endl;
	return 0;
}