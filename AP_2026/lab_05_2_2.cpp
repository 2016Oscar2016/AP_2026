// Lab_05_2_2.cpp
// Пастернак Олександр
// Лабораторна робота № 5.2
// Обчислення суми ряду Тейлора зa допомогою функцій
// Варіант 0.23

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double S(const double x, const double eps, int& n);   // повертає суму ряду, n - кількість доданків
double A(const double x, const int n, double a);      // повертає наступний доданок ряду

int main()
{
    double xp, xk, x, dx, eps;      // початок, кінець, крок, точність
    double s = 0;                   // сума ряду
    int n = 0;                      // кількість доданків

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
        s = S(x, eps, n);

        cout << "|" << setw(7) << setprecision(2) << x
            << " |" << setw(10) << setprecision(5) << exp(x * x)
            << " |" << setw(10) << setprecision(5) << s
            << " |" << setw(5) << n << " |" << endl;

        x += dx;
    }

    cout << "-----------------------------------------" << endl;

    return 0;
}

// x, eps - вхідні параметри; n - вихідний (кількість доданків)
double S(const double x, const double eps, int& n)
{
    n = 0;
    double a = 1;                   // перший доданок a0 = 1
    double s = a;
    do
    {
        n++;
        a = A(x, n, a);
        s += a;
    } while (fabs(a) >= eps);
    return s;
}

// x, n - вхідні параметри; a - попередній доданок
double A(const double x, const int n, double a)
{
    double R = x * x / n;           // коефіцієнт рекурентності
    a *= R;
    return a;
}
