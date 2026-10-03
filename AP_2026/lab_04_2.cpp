// Lab_04_2.cpp
// Пастернак Олександр
// Лабораторна робота № 4.2
// Цикли.
// Варіант 0.23
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double x, xp, xk, dx, A, B, y;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;

    cout << fixed;
    cout << "-------------------------" << endl;
    cout << "|" << setw(8) << "x" << " |" << setw(12) << "y" << " |" << endl;
    cout << "-------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        A = x * x * sin(4 * x / 3);              // частина A: x^2 * sin(4x/3)

        if (x < -5)
            B = 1 / tan(x);                      // частина B: ctg x
        else
            if (x < 0)
                B = 4 - x * x / 2;               // частина B: 4 - x^2 / 2
            else
                B = log10(x * x) - 4 * x / 3;    // частина B: lg(x^2) - 4x/3

        y = A + B;

        cout << "|" << setw(8) << setprecision(2) << x
            << " |" << setw(12) << setprecision(3) << y << " |" << endl;

        x += dx;
    }

    cout << "-------------------------" << endl;

    return 0;
}
