// Лабораторна робота № 6.2, спосіб 2 (рекурсивний), варіант 23
// Перша половина масиву a (2n елементів) міняється місцями з другою
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//const int n = 5;
//int a[n] = { 1, 2, 3, 4, 5};

// заповнює масив a з size елементів випадковими числами з [Low, High]; i - поточний індекс
void Create(int* a, const int size, const int Low, const int High, const int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// виводить масив a з size елементів у рядок; i - поточний індекс
void Print(const int* a, const int size, const int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

// міняє місцями першу половину масиву (n елементів) з другою; i - поточний індекс
void Swap(int* a, const int n, const int i)
{
    int x = a[i];            // елемент з першої половини
    a[i] = a[i + n];         // на його місце - відповідний з другої
    a[i + n] = x;
    if (i < n - 1)
        Swap(a, n, i + 1);
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 5;         // половина кількості елементів
    int a[2 * n];            // масив з 2n елементів
    int Low = -10;
    int High = 10;

    Create(a, 2 * n, Low, High, 0);
    Print(a, 2 * n, 0);

    Swap(a, n, 0);
    Print(a, 2 * n, 0);

    return 0;
}