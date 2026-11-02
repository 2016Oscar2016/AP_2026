// Lab_7_1_iter.cpp
// Лабораторна робота № 7.1, спосіб 1 (ітераційний).
// Пошук заданих елементів та впорядкування рядків матриці.
// Варіант 23

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// заповнює матрицю a (rowCount x colCount) випадковими числами з [Low, High]
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);

// виводить матрицю a у вигляді таблиці
void Print(int** a, const int rowCount, const int colCount);

// впорядковує рядки матриці a за ключами (методом обміну)
void Sort(int** a, const int rowCount, const int colCount);

// міняє місцями рядки row1 і row2 матриці a
void Change(int** a, const int row1, const int row2, const int colCount);

// обчислює суму S та кількість k елементів, що задовольняють критерій,
// і замінює ці елементи нулями (S і k - вихідні параметри)
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));

    int Low = 8;            // нижня межа значень
    int High = 73;          // верхня межа значень

    int rowCount = 7;       // кількість рядків матриці
    int colCount = 6;       // кількість стовпців матриці

    int** a = new int* [rowCount];      // динамічна матриця
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);
    Sort(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    int S = 0;              // сума заданих елементів
    int k = 0;              // кількість заданих елементів
    Calc(a, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void Sort(int** a, const int rowCount, const int colCount)
{
    for (int i0 = 0; i0 < rowCount - 1; i0++)           // метод обміну ("бульбашки")
        for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
            if ((a[i1][0] > a[i1 + 1][0])               // 1-й стовпчик - за зростанням
                ||
                (a[i1][0] == a[i1 + 1][0] &&
                    a[i1][1] < a[i1 + 1][1])               // 2-й стовпчик - за спаданням
                ||
                (a[i1][0] == a[i1 + 1][0] &&
                    a[i1][1] == a[i1 + 1][1] &&
                    a[i1][3] < a[i1 + 1][3]))              // 4-й стовпчик - за спаданням
                Change(a, i1, i1 + 1, colCount, _placeholder_);
}

void Change(int** a, const int row1, const int row2, const int colCount, int j);
{
    int tmp;                                            // тимчасова змінна для обміну
    for (int j = 0; j < colCount; j++)
    {
        tmp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = tmp;
    }
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (a[i][j] % 2 == 0 || !(a[i][j] % 8 == 0))     // критерій: парні АБО крім кратних 8
            {
                S += a[i][j];
                k++;
                a[i][j] = 0;
            }
}