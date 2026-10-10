// Lab_05_1.cpp
// Пастернак Олександр
// Лабораторна робота № 5.1
// Функції, що містять арифметичний вираз.
// Варіант 0.23

#include <iostream>
#include <cmath>

using namespace std;

double g(const double a, const double b);   // прототип

int main()
{
    double s, t;

    cout << "s = "; cin >> s;
    cout << "t = "; cin >> t;

    double g1 = g(2, s);
    double g2 = g(t, 1);
    double g3 = g(s, t);

    double c = (g1 + pow(1 + g2 * g2, 3)) / sqrt(1 + g3 * g3);   // (g(2,s) + (1 + g(t,1)^2)^3) / sqrt(1 + g(s,t)^2)

    cout << "c = " << c << endl;

    return 0;
}

double g(const double a, const double b)    // визначення
{
    double r = a * b / (a * a + b * b);     // g(a, b) = ab / (a^2 + b^2)
    return r;
}