// Лабораторна робота № 6.2, спосіб 1 (ітераційний), варіант 23
// Перша половина масиву a (2n елементів) міняється місцями з другою

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// заповнює масив a з size елементів випадковими числами з [Low, High]
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// виводить масив a з size елементів у рядок
void Print(const int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// міняє місцями першу половину масиву (n елементів) з другою
void Swap(int* a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        int x = a[i];        // елемент з першої половини
        a[i] = a[i + n];     // на його місце - відповідний з другої
        a[i + n] = x;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 5;         // половина кількості елементів
    int a[2 * n];            // масив з 2n елементів
    int Low = -10;
    int High = 10;

    Create(a, 2 * n, Low, High);
    Print(a, 2 * n);

    Swap(a, n);
    Print(a, 2 * n);

    return 0;
}