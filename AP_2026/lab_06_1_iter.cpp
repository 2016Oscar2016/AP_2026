// Lab_06_1.cpp
// Пастернак Олександр
// Лабораторна робота № 6.1
// Варіант 0.23

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// заповнює масив a випадковими числами з [Low, High]
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// виводить масив a у рядок
void Print(const int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// кількість додатних елементів з індексами, не кратними 4
int Count(const int* a, const int size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
        if (a[i] > 0 && i % 4 != 0)
            k++;
    return k;
}

// сума додатних елементів з індексами, не кратними 4
int Sum(const int* a, const int size)
{
    int S = 0;
    for (int i = 0; i < size; i++)
        if (a[i] > 0 && i % 4 != 0)
            S += a[i];
    return S;
}

// замінює нулями додатні елементи з індексами, не кратними 4
void Zero(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        if (a[i] > 0 && i % 4 != 0)
            a[i] = 0;
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 20;
    int t[n];
    int Low = -14;
    int High = 7;

    Create(t, n, Low, High);
    Print(t, n);

    cout << "k = " << Count(t, n) << endl;
    cout << "S = " << Sum(t, n) << endl;

    Zero(t, n);
    Print(t, n);

    return 0;
}