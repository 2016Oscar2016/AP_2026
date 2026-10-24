// Lab_06_1.cpp
// Пастернак Олександр
// Лабораторна робота № 6.1
// Варіант 0.23

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// заповнює масив a випадковими числами з [Low, High]; i - поточний індекс
void Create(int* a, const int size, const int Low, const int High, const int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// виводить масив a у рядок
void Print(const int* a, const int size, const int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

// кількість додатних елементів з індексами, не кратними 4
int Count(const int* a, const int size, const int i)
{
    if (i < size)
    {
        if (a[i] > 0 && i % 4 != 0)
            return 1 + Count(a, size, i + 1);
        else
            return Count(a, size, i + 1);
    }
    else
        return 0;
}

// сума додатних елементів з індексами, не кратними 4
int Sum(const int* a, const int size, const int i)
{
    if (i < size)
    {
        if (a[i] > 0 && i % 4 != 0)
            return a[i] + Sum(a, size, i + 1);
        else
            return Sum(a, size, i + 1);
    }
    else
        return 0;
}

// замінює нулями додатні елементи з індексами, не кратними 4
void Zero(int* a, const int size, const int i)
{
    if (a[i] > 0 && i % 4 != 0)
        a[i] = 0;
    if (i < size - 1)
        Zero(a, size, i + 1);
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 20;
    int t[n];
    int Low = -14;
    int High = 7;

    Create(t, n, Low, High, 0);
    Print(t, n, 0);

    cout << "k = " << Count(t, n, 0) << endl;
    cout << "S = " << Sum(t, n, 0) << endl;

    Zero(t, n, 0);
    Print(t, n, 0);

    return 0;
}