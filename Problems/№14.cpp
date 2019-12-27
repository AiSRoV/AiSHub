#include <iostream>

using namespace std;

int main() {
	long long sum, l1, r1, l2, r2;

	cin >> sum >> l1 >> r1 >> l2 >> r2;

	long long k1, k2;
	bool stop = false;

	for (int i = l1; i <= r1; i++) {
		for (int j = l2; j <= r2; j++) {
			if ((i + j) == sum) {
				k1 = i;
				k2 = j;
				stop = true;
				break;
			}
			else if ((i + j) > sum) break;
		}
		if (stop) break;
	}

	if (stop) cout << k1 << ' ' << k2 << endl;
	else cout << -1;

	return 0;
}