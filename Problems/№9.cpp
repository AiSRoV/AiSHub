#include <iostream>
#include <ctime>

using  namespace std;

int main() {

	bool chis = true;
	bool m;
	int pred;
	srand(time(NULL));

	while (chis) {
		int num = rand() % 101;
		m = false;
		for (int i = 0; i < 5; i++) {
			cin >> pred;
			if (pred < num) {
				cout << "����� ������" << endl;
			}
			else {
				if (pred > num) {
					cout << "����� ������" << endl;
				}
				else {
					cout << "�� �������!" << endl;
					m = true;
					break;
				}
			}
		}
		if (!m) {
			cout << "�� ���������. ���� ��������: " << num << endl;
		}
		cout << "������ �������? (1 - �� )" << endl;
		cin >> pred;
		chis = pred == 1 ? true : false;
	}
	return 0;
}