// Лабораторна робота № 6.4, спосіб 2 (рекурсивний), варіант 23
// Динамічний масив з n цілих елементів (n вводиться з клавіатури)
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// заповнює масив a з n елементів випадковими числами з [Low, High]; i - поточний індекс
void Create(int* a, const int n, const int Low, const int High, const int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < n - 1)
        Create(a, n, Low, High, i + 1);
}

// виводить масив a з n елементів у рядок; i - поточний індекс
void Print(const int* a, const int n, const int i)
{
    cout << setw(4) << a[i];
    if (i < n - 1)
        Print(a, n, i + 1);
    else
        cout << endl;
}

// повертає добуток елементів з парними номерами (0, 2, 4, ...); i - поточний індекс
int ProductEven(const int* a, const int n, const int i)
{
    if (i < n)
        return a[i] * ProductEven(a, n, i + 2);
    else
        return 1;
}

// повертає індекс першого нульового елемента (або -1, якщо нулів немає); i - поточний індекс
int FirstZero(const int* a, const int n, const int i)
{
    if (i < n)
    {
        if (a[i] == 0)
            return i;
        else
            return FirstZero(a, n, i + 1);
    }
    else
        return -1;
}

// повертає індекс останнього нульового елемента (або -1, якщо нулів немає);
// i - поточний індекс, іде від кінця масиву до початку
int LastZero(const int* a, const int i)
{
    if (i >= 0)
    {
        if (a[i] == 0)
            return i;
        else
            return LastZero(a, i - 1);
    }
    else
        return -1;
}

// повертає суму елементів від індексу i до last (сам last не входить)
int SumBetween(const int* a, const int last, const int i)
{
    if (i < last)
        return a[i] + SumBetween(a, last, i + 1);
    else
        return 0;
}

// один прохід методу обміну: від'ємний елемент, за яким іде невід'ємний, міняються місцями
void Find(int* a, const int size, const int j)
{
    if (j < size - 1)
    {
        if (a[j] < 0 && a[j + 1] >= 0)
        {
            int x = a[j];
            a[j] = a[j + 1];
            a[j + 1] = x;
        }
        Find(a, size, j + 1);
    }
}

// переставляє елементи: спочатку додатні (і нулі), потім від'ємні;
// відносний порядок зберігається; i - номер проходу
void Rearrange(int* a, const int n, const int i)
{
    if (i < n - 1)
    {
        Find(a, n - i, 0);
        Rearrange(a, n, i + 1);
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

    Create(a, n, Low, High, 0);
    Print(a, n, 0);

    cout << "P = " << ProductEven(a, n, 0) << endl;

    int first = FirstZero(a, n, 0);
    int last = LastZero(a, n - 1);
    cout << "S = " << SumBetween(a, last, first + 1) << endl;

    Rearrange(a, n, 0);
    Print(a, n, 0);

    delete[] a;              // звільняємо пам'ять
    return 0;
}