// Lab_04_3.cpp
// Пастернак Олександр
// Лабораторна робота № 4.3
// Цикли.
// Варіант 0.23
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double a, b, c, x, xp, xk, dx, F;

    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;

    cout << fixed;
    cout << "-------------------------" << endl;
    cout << "|" << setw(8) << "x" << " |" << setw(12) << "F" << " |" << endl;
    cout << "-------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        if (a < 0 && c != 0)
            F = a * x * x + b * x + c;       // F = ax^2 + bx + c
        else
            if (a > 0 && c == 0)
                F = -a / (x - b);           // F = -a / (x - b)
            else
                F = a * (x + c);           // F = a(x + c).

        cout << "|" << setw(8) << setprecision(2) << x
            << " |" << setw(12) << setprecision(3) << F << " |" << endl;

        x += dx;
    }

    cout << "-------------------------" << endl;

    return 0;
}