// Lab_05_3.cpp
// Пастернак Олександр
// Лабораторна робота № 5.3
// Функції, що містять розгалуження та цикли з рекурентними співвідношеннями
// Варіант 0.23

// Лабораторна робота № 5.3
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double j(const double x);       // повертає значення допоміжної функції j(x)

int main()
{
    double kp, kk, k, dk, z;    // початок, кінець, поточне k, крок, значення виразу
    int n;                      // кількість відрізків розбиття

    cout << "kp = "; cin >> kp;
    cout << "kk = "; cin >> kk;
    cout << "n = "; cin >> n;

    dk = (kk - kp) / n;

    cout << fixed;
    cout << "---------------------------" << endl;
    cout << "|" << setw(10) << "k" << " |" << setw(12) << "z" << " |" << endl;
    cout << "---------------------------" << endl;

    k = kp;
    while (k <= kk)
    {
        z = j(1 + k + j(k)) + pow(j(1 + k * k), 2);

        cout << "|" << setw(10) << setprecision(3) << k
            << " |" << setw(12) << setprecision(5) << z << " |" << endl;

        k += dk;
    }

    cout << "---------------------------" << endl;

    return 0;
}

// x - вхідний параметр
double j(const double x)
{
    if (fabs(x) >= 1)
        return (cos(x) + exp(-fabs(x))) / (cos(x * x) + 1);
    else
    {
        double a = x;               // перший доданок a0 = x
        double S = a;               // сума ряду
        for (int i = 1; i <= 5; i++)
        {
            a *= x * x / ((2 * i) * (2 * i + 1));   // рекурентне співвідношення
            S += a;
        }
        return S;
    }
}