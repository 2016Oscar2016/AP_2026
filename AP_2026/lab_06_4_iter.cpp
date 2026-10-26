// Лабораторна робота № 6.4, спосіб 1 (ітераційний), варіант 23
// Динамічний масив з n цілих елементів (n вводиться з клавіатури)
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// заповнює масив a з n елементів випадковими числами з [Low, High]
void Create(int* a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// виводить масив a з n елементів у рядок
void Print(const int* a, const int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// повертає добуток елементів з парними номерами (0, 2, 4, ...)
int ProductEven(const int* a, const int n)
{
    int p = 1;
    for (int i = 0; i < n; i += 2)
        p *= a[i];
    return p;
}

// повертає індекс першого нульового елемента (або -1, якщо нулів немає)
int FirstZero(const int* a, const int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] == 0)
            return i;
    return -1;
}

// повертає індекс останнього нульового елемента (або -1, якщо нулів немає)
int LastZero(const int* a, const int n)
{
    for (int i = n - 1; i >= 0; i--)
        if (a[i] == 0)
            return i;
    return -1;
}

// повертає суму елементів між індексами first і last (самі first і last не входять)
int SumBetween(const int* a, const int first, const int last)
{
    int S = 0;
    for (int i = first + 1; i < last; i++)
        S += a[i];
    return S;
}

// переставляє елементи: спочатку додатні (і нулі), потім від'ємні;
// відносний порядок зберігається (метод обміну сусідніх елементів)
void Rearrange(int* a, const int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (a[j] < 0 && a[j + 1] >= 0)
            {
                int x = a[j];
                a[j] = a[j + 1];
                a[j + 1] = x;
            }
}

int main()
{
    srand((unsigned)time(NULL));

    int n;
    cout << "n = ";
    cin >> n;

    int* a = new int[n];     // динамічний масив
    int Low = -5;
    int High = 5;

    Create(a, n, Low, High);
    Print(a, n);

    cout << "P = " << ProductEven(a, n) << endl;

    int first = FirstZero(a, n);
    int last = LastZero(a, n);
    cout << "S = " << SumBetween(a, first, last) << endl;

    Rearrange(a, n);
    Print(a, n);

    delete[] a;              // звільняємо пам'ять
    return 0;
}