// Lab_04_6.cpp
// Пастернак Олександр
// Лабораторна робота № 4.6
// Цикли.
// Варіант 0.23

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double S, P;
    int i, k;

    // 1 спосіб: while
    S = 0;
    i = 1;
    while (i <= 15)
    {
        P = 1;
        k = 1;
        while (k <= i)
        {
            P *= sqrt(k);                                   // добуток коренів sqrt(1)*...*sqrt(i)
            k++;
        }
        S += (sin(10 * i) + cos(10 * i)) / P;               // доданок суми
        i++;
    }
    cout << S << endl;

    // 2 спосіб: do-while
    S = 0;
    i = 1;
    do
    {
        P = 1;
        k = 1;
        do
        {
            P *= sqrt(k);                                   // добуток коренів sqrt(1)*...*sqrt(i)
            k++;
        } while (k <= i);
        S += (sin(10 * i) + cos(10 * i)) / P;               // доданок суми
        i++;
    } while (i <= 15);
    cout << S << endl;

    // 3 спосіб: for (збільшення)
    S = 0;
    for (i = 1; i <= 15; i++)
    {
        P = 1;
        for (k = 1; k <= i; k++)
            P *= sqrt(k);                                   // добуток коренів sqrt(1)*...*sqrt(i)
        S += (sin(10 * i) + cos(10 * i)) / P;               // доданок суми
    }
    cout << S << endl;

    // 4 спосіб: for (зменшення)
    S = 0;
    for (i = 15; i >= 1; i--)
    {
        P = 1;
        for (k = i; k >= 1; k--)
            P *= sqrt(k);                                   // добуток коренів sqrt(1)*...*sqrt(i)
        S += (sin(10 * i) + cos(10 * i)) / P;               // доданок суми
    }
    cout << S << endl;

    return 0;
}