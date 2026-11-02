/*            стовпчик j
            0      1      2      3
         ┌──────┬──────┬──────┬──────┐
  рядок 0│ (0,0)│ (0,1)│ (0,2)│ (0,3)│
    i    │  ВИЩЕ│  ВИЩЕ│  ВИЩЕ│  ДІАГ│
         ├──────┼──────┼──────┼──────┤
       1 │ (1,0)│ (1,1)│ (1,2)│ (1,3)│
         │  ВИЩЕ│  ВИЩЕ│  ДІАГ│ НИЖЧЕ│
         ├──────┼──────┼──────┼──────┤
       2 │ (2,0)│ (2,1)│ (2,2)│ (2,3)│
         │  ВИЩЕ│  ДІАГ│ НИЖЧЕ│ НИЖЧЕ│
         ├──────┼──────┼──────┼──────┤
       3 │ (3,0)│ (3,1)│ (3,2)│ (3,3)│
         │  ДІАГ│ НИЖЧЕ│ НИЖЧЕ│ НИЖЧЕ│
         └──────┴──────┴──────┴──────┘
            0      1      2      3

*/

// Lab_7_2_rec.cpp
// Лабораторна робота № 7.2.2
// Опрацювання багатовимірних масивів рекурсивними способами.
// Варіант 23: міняє місцями мінімальний елемент над побічною діагоналлю
// та максимальний елемент під нею; знаходить суму цих елементів.

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// заповнює рядки матриці a (N x N) випадковими числами з [Low, High]; rowNo - номер поточного рядка
void CreateRows(int** a, const int N, const int Low, const int High, int rowNo);

// заповнює поточний рядок rowNo; colNo - номер поточного стовпчика
void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo);

// виводить рядки матриці a у вигляді таблиці; rowNo - номер поточного рядка
void PrintRows(int** a, const int N, int rowNo);

// виводить поточний рядок rowNo; colNo - номер поточного стовпчика
void PrintRow(int** a, const int rowNo, const int N, int colNo);

// шукає мінімальний елемент над побічною діагоналлю (i + j < N - 1);
// row, col - вихідні параметри (перед викликом row = 0, col = 0; потрібно N >= 2); i - номер поточного рядка
void SearchMinAboveRows(int** a, const int N, int i, int& row, int& col);

// те саме для поточного рядка i; j - номер поточного стовпчика
void SearchMinAboveRow(int** a, const int N, const int i, int j, int& row, int& col);

// шукає максимальний елемент під побічною діагоналлю (i + j > N - 1);
// row, col - вихідні параметри (перед викликом row = N - 1, col = N - 1; потрібно N >= 2); i - номер поточного рядка
void SearchMaxBelowRows(int** a, const int N, int i, int& row, int& col);

// те саме для поточного рядка i; j - номер поточного стовпчика
void SearchMaxBelowRow(int** a, const int N, const int i, int j, int& row, int& col);

// міняє місцями елементи a[row1][col1] і a[row2][col2]
void SwapElements(int** a, const int row1, const int col1, const int row2, const int col2);

// повертає суму елементів a[row1][col1] і a[row2][col2]
int SumTwo(int** a, const int row1, const int col1, const int row2, const int col2);

int main()
{
    srand((unsigned)time(NULL));

    int Low = -20;          // нижня межа значень
    int High = 20;          // верхня межа значень

    int N;                  // розмір матриці N x N
    cout << "N = "; cin >> N;

    int** a = new int* [N];             // динамічна матриця
    for (int i = 0; i < N; i++)
        a[i] = new int[N];

    CreateRows(a, N, Low, High, 0);
    PrintRows(a, N, 0);

    if (N < 2)
        cout << "there are no elements above and below the diagonal" << endl;
    else
    {
        int minRow = 0, minCol = 0;             // положення мінімуму над діагоналлю
        int maxRow = N - 1, maxCol = N - 1;     // положення максимуму під діагоналлю

        SearchMinAboveRows(a, N, 0, minRow, minCol);
        SearchMaxBelowRows(a, N, 0, maxRow, maxCol);
        cout << "min above = " << a[minRow][minCol] << endl;
        cout << "max below = " << a[maxRow][maxCol] << endl;

        int S = SumTwo(a, minRow, minCol, maxRow, maxCol);     // сума цих двох елементів
        cout << "S = " << S << endl;

        SwapElements(a, minRow, minCol, maxRow, maxCol);
        PrintRows(a, N, 0);
    }

    for (int i = 0; i < N; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int N, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, N, Low, High, 0);
    if (rowNo < N - 1)
        CreateRows(a, N, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int N, int rowNo)
{
    PrintRow(a, rowNo, N, 0);
    if (rowNo < N - 1)
        PrintRows(a, N, rowNo + 1);
    else
        cout << endl;
}

void SearchMinAboveRow(int** a, const int N, const int i, int j, int& row, int& col)
{
    if (i + j < N - 1 && a[i][j] < a[row][col])
    {
        row = i;
        col = j;
    }
    if (j < N - 1)
        SearchMinAboveRow(a, N, i, j + 1, row, col);
}

void SearchMinAboveRows(int** a, const int N, int i, int& row, int& col)
{
    SearchMinAboveRow(a, N, i, 0, row, col);
    if (i < N - 1)
        SearchMinAboveRows(a, N, i + 1, row, col);
}

void SearchMaxBelowRow(int** a, const int N, const int i, int j, int& row, int& col)
{
    if (i + j > N - 1 && a[i][j] > a[row][col])
    {
        row = i;
        col = j;
    }
    if (j < N - 1)
        SearchMaxBelowRow(a, N, i, j + 1, row, col);
}

void SearchMaxBelowRows(int** a, const int N, int i, int& row, int& col)
{
    SearchMaxBelowRow(a, N, i, 0, row, col);
    if (i < N - 1)
        SearchMaxBelowRows(a, N, i + 1, row, col);
}

void SwapElements(int** a, const int row1, const int col1, const int row2, const int col2)
{
    int tmp = a[row1][col1];            // тимчасова змінна для обміну
    a[row1][col1] = a[row2][col2];
    a[row2][col2] = tmp;
}

int SumTwo(int** a, const int row1, const int col1, const int row2, const int col2)
{
    return a[row1][col1] + a[row2][col2];
}