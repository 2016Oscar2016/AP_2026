// Lab_05_2_1.cpp
// Пастернак Олександр
// Лабораторна робота № 5.2
// Обчислення суми ряду Тейлора зa допомогою функцій
// Варіант 0.23

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void S(const double x, const double eps, int& n, double& s);   // сума ряду і кількість доданків
void A(const double x, const int n, double& a);                // наступний доданок ряду

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
        S(x, eps, n, s);

        cout << "|" << setw(7) << setprecision(2) << x
            << " |" << setw(10) << setprecision(5) << exp(x * x)
            << " |" << setw(10) << setprecision(5) << s
            << " |" << setw(5) << n << " |" << endl;

        x += dx;
    }

    cout << "-----------------------------------------" << endl;

    return 0;
}

// x, eps - вхідні параметри; n, s - вихідні (кількість доданків і сума)
void S(const double x, const double eps, int& n, double& s)
{
    n = 0;
    double a = 1;                   // перший доданок a0 = 1
    s = a;
    do
    {
        n++;
        A(x, n, a);
        s += a;
    } while (fabs(a) >= eps);
}

// x, n - вхідні параметри; a - попередній доданок, змінюється на наступний
void A(const double x, const int n, double& a)
{
    double R = x * x / n;           // коефіцієнт рекурентності
    a *= R;
}
