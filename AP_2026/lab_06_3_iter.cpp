// Лабораторна робота № 6.3, спосіб 1 (ітераційний), варіант 23
// Сума квадратів елементів масиву: звичайна функція та шаблон

#include <iostream>
#include <iomanip>
using namespace std;

// виводить масив a з size елементів у рядок (шаблон - для будь-якого типу)
template <typename T>
void Print(const T* a, const int size);

// сума квадратів елементів масиву цілих чисел (звичайна функція)
int SumSquares(int* a, const int size);

// сума квадратів елементів масиву будь-якого типу (шаблон)
template <typename T>
T SumSquares(T* a, const int size);

int main()
{
    const int n = 10;

    int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Print(a, n);
    int s1 = SumSquares(a, n);
    cout << "SumSquares(a, n) = " << s1 << endl;

    int s2 = SumSquares<int>(a, n);
    cout << "SumSquares<int>(a, n) = " << s2 << endl;

    double b[n] = { 1.1, 2.2, 3.3, 4.3, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0 };
    Print(b, n);
    double s3 = SumSquares<double>(b, n);
    cout << "SumSquares<double>(b, n) = " << s3 << endl;

    return 0;
}

template <typename T>
void Print(const T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(6) << a[i];
    cout << endl;
}

int SumSquares(int* a, const int size)         // звичайні функції (як в методичці)
{
    int s = 0;
    for (int i = 0; i < size; i++)
        s += a[i] * a[i];
    return s;
}

template <typename T>
T SumSquares(T* a, const int size)          // шаблони функції
{
    T s = T();                    // нульове значення типу T
    for (int i = 0; i < size; i++)
        s += a[i] * a[i];
    return s;
}