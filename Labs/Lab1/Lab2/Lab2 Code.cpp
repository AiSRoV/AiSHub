#include <iostream>
#include <cmath>

using namespace std;

int main(){

    double a, b ,x1, x2, d, z, xma, xmi, x;

    bool flag = true;

    cin >> a >> b >> x1 >> x2 >> d;
    cout << "|  " << 'x' << " | " << 'y' << " |" <<  endl << "|-----|-----|" << endl;

    x = x1;
    xma = 0;
    xmi = 0;

    for (int i = 0; i <= (x2 -x1)/d; i ++, x += d){

        if (x <= a) z = abs(x) + sin(x);
        else if ((a < x) && (x < b)) z = log(abs(x)) / log(3);
        else if (x >= b) z = tan(x);

        if (flag) {
            xma = z;
            xmi = z;
            flag = false;
        } else if (z > xma) xma = z;
        else if (z < xmi) xmi = z;

        cout <<  "|  " << x << " | " << z << " |" <<  endl;
    }
    cout << endl << "max: " << xma << "  min: " << xmi << endl;

    return 0;
}
