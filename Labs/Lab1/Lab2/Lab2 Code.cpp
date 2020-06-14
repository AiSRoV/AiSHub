#include <iostream>
#include <cmath>

using namespace std;

bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
    // Проверяем числа на их близость - это нужно в случаях, когда сравниваемые числа являются нулевыми или около нуля
    double diff = fabs(a - b);
    if (diff <= absEpsilon)
        return true;

    // В противном случае, возвращаемся к алгоритму Кнута
    return diff <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * relEpsilon);
}

int main() {

    double a, b, x1, x2, d, z, xma, xmi, x;

    bool flag = true;

    cin >> a >> b >> x1 >> x2 >> d;
    cout << "|  " << 'x' << " | " << 'y' << " |" << endl << "|-----|-----|" << endl;

    x = x1;
    xma = 0;
    xmi = 0;

    for (int i = 0; i <= (x2 - x1) / d; i++, x += d) {

        if (approximatelyEqualAbsRel(x, a, 1e-12, 1e-8)) z = abs(x) + sin(x);
        else if (x < a) z = abs(x) + sin(x);
        else if ((a < x) && (x < b)) z = log(abs(x)) / log(3);
        else if (approximatelyEqualAbsRel(x, b, 1e-12, 1e-8)) z = tan(x);
        else if (x > b) z = tan(x);

        if (flag) {
            xma = z;
            xmi = z;
            flag = false;
        }
        else if (z > xma) xma = z;
        else if (z < xmi) xmi = z;

        cout << "|  " << x << " | " << z << " |" << endl;
    }
    cout << endl << "max: " << xma << "  min: " << xmi << endl;

    return 0;
}
