// Lab_04_7.cpp
// Пастернак Олександр
// Лабораторна робота № 4.7
// Цикли.
// Варіант 0.23

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double xp, xk, x, dx, eps, a, R, S;
    int n;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-----------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |" << setw(10) << "exp(x*x)" << " |"
        << setw(10) << "S" << " |" << setw(5) << "n" << " |" << endl;
    cout << "-----------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        n = 0;
        a = 1;                      // перший доданок a0 = 1
        S = a;
        do
        {
            n++;
            R = x * x / n;          // коефіцієнт рекурентності: a(n) = a(n-1) * x^2 / n
            a *= R;
            S += a;
        } while (fabs(a) >= eps);

        cout << "|" << setw(7) << setprecision(2) << x
            << " |" << setw(10) << setprecision(5) << exp(x * x)
            << " |" << setw(10) << setprecision(5) << S
            << " |" << setw(5) << n << " |" << endl;

        x += dx;
    }

    cout << "-----------------------------------------" << endl;

    return 0;
}
