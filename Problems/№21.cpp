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
		cout << "�������� �������: " << att << endl;
		cin >> r >> c;
		if ((r < 0) || (r > 9) || (c < 0) || (c > 7)) cout << "����� �� �����" << endl;
		else if (a[r][c] == -1) cout << "�� ���������� ����" << endl;
		else if (a[r][c] == 1) {
			cout << "�� ��������" << endl;
			break;
		}
		else {
			cout << "�� ������ �����" << endl;
			a[r][c] = -1;
			att--;
		}
	}
	if (!att) cout << "�� ���������" << endl;
	cout << "���������� ������: " << num / 8 << ' ' << num % 8 << endl;
	return 0;
}