#include <iostream>

using namespace std;

double BMI(double wei, double hei) {
	return wei / (hei * hei);
}

void pBMI(double BMI) {
	if (BMI < 18.5) cout << "Underweight";
	else if ((18.5 <= BMI) && (BMI < 25.0)) cout << "Normal weight";
	else if ((25.0 <= BMI) && (BMI < 30.0)) cout << "Overweight";
	else cout << "Obesity";
}

int main() {

	double weight, height;

	cout << "¬ведите вес: ";
	cin >> weight;

	cout << "¬ведите рост: ";
	cin >> height;

	pBMI(BMI(weight, height / 100));

	return 0;
}