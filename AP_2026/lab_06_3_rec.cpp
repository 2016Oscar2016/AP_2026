// Лабораторна робота № 6.3, спосіб 2 (рекурсивний), варіант 23
// Сума квадратів елементів масиву: звичайна функція та шаблон
#include <iostream>
#include <iomanip>
using namespace std;

// виводить масив a з size елементів у рядок (шаблон); i - поточний індекс
template <typename T>
void Print(const T* a, const int size, const int i);

// сума квадратів елементів масиву цілих чисел (звичайна функція); i - поточний індекс
int SumSquares(int* a, const int size, const int i);

// сума квадратів елементів масиву будь-якого типу (шаблон); i - поточний індекс
template <typename T>
T SumSquares(T* a, const int size, const int i);

int main()
{
    const int n = 10;

    int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Print(a, n, 0);
    int s1 = SumSquares(a, n, 0);
    cout << "SumSquares(a, n) = " << s1 << endl;

    int s2 = SumSquares<int>(a, n, 0);
    cout << "SumSquares<int>(a, n) = " << s2 << endl;

    double b[n] = { 1.1, 2.2, 3.3, 4.3, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0 };
    Print(b, n, 0);
    double s3 = SumSquares<double>(b, n, 0);
    cout << "SumSquares<double>(b, n) = " << s3 << endl;

    return 0;
}

template <typename T>
void Print(const T* a, const int size, const int i)
{
    cout << setw(6) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

int SumSquares(int* a, const int size, const int i)
{
    if (i < size)
        return a[i] * a[i] + SumSquares(a, size, i + 1);
    else
        return 0;
}

template <typename T>
T SumSquares(T* a, const int size, const int i)
{
    if (i < size)
        return a[i] * a[i] + SumSquares<T>(a, size, i + 1);
    else
        return T();               // нульове значення типу T
}