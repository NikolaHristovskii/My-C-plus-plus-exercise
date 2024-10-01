#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const double a = 9, b = 6, c = 1;
    double x1, x2;

    cout << "Your coefficients are:\nfor \"a\" = " << a << "\nfor \"b\" = " << b << "\nfor \"c\" = " << c << endl;

    if (a == 0.0 || b == 0.0 || c == 0.0) {
        cout << "The equation cannot work because you have entered 0, please change the coefficient!" << endl;
    }
    else {
        x1 = -b + sqrt(pow(b, 2) - 4 * a * c) / 2 * a;
        x2 = -b - sqrt(pow(b, 2) - 4 * a * c) / 2 * a;

        cout << "The roots are:\nx1 = " << x1 << "\nx2 = " << x2 << endl;
    }
    return 0;
}
