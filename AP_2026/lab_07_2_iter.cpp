/*            стовпчик j
            0      1      2      3
         ┌──────┬──────┬──────┬──────┐
  рядок 0│ (0,0)│ (0,1)│ (0,2)│ (0,3)│
    i    │  ВИЩЕ│  ВИЩЕ│  ВИЩЕ│  ДІАГ│
         ├──────┼──────┼──────┼──────┤
       1 │ (1,0)│ (1,1)│ (1,2)│ (1,3)│
         │  ВИЩЕ│  ВИЩЕ│  ДІАГ│  НИЖЧЕ│
         ├──────┼──────┼──────┼──────┤
       2 │ (2,0)│ (2,1)│ (2,2)│ (2,3)│
         │  ВИЩЕ│  ДІАГ│ НИЖЧЕ│ НИЖЧЕ│
         ├──────┼──────┼──────┼──────┤
       3 │ (3,0)│ (3,1)│ (3,2)│ (3,3)│
         │  ДІАГ│ НИЖЧЕ│ НИЖЧЕ│ НИЖЧЕ│
         └──────┴──────┴──────┴──────┘
            0      1      2      3
         
*/             
            
// Лабораторна робота № 7.2.1
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 23: міняє місцями мінімальний елемент над побічною діагоналлю
// та максимальний елемент під нею; знаходить суму цих елементів.

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// заповнює матрицю a (n x n) випадковими числами з [Low, High]
void Create(int** a, const int n, const int Low, const int High);

// виводить матрицю a у вигляді таблиці
void Print(int** a, const int n);

// шукає мінімальний елемент над побічною діагоналлю (i + j < n - 1);
// row, col - вихідні параметри: рядок і стовпчик цього елемента (потрібно n >= 2)
void SearchMinAbove(int** a, const int n, int& row, int& col);

// шукає максимальний елемент під побічною діагоналлю (i + j > n - 1);
// row, col - вихідні параметри: рядок і стовпчик цього елемента (потрібно n >= 2)
void SearchMaxBelow(int** a, const int n, int& row, int& col);

// міняє місцями елементи a[row1][col1] і a[row2][col2]
void SwapElements(int** a, const int row1, const int col1, const int row2, const int col2);

// повертає суму елементів a[row1][col1] і a[row2][col2]
int SumTwo(int** a, const int row1, const int col1, const int row2, const int col2);

int main()
{
    srand((unsigned)time(NULL));

    int Low = -20;          // нижня межа значень
    int High = 20;          // верхня межа значень

    int n;                  // розмір матриці n x n
    cout << "n = "; cin >> n;

    int** a = new int* [n];             // динамічна матриця
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High);
    Print(a, n);

    if (n < 2)
        cout << "there are no elements above and below the diagonal" << endl;
    else
    {
        int minRow, minCol;             // положення мінімуму над діагоналлю
        int maxRow, maxCol;             // положення максимуму під діагоналлю

        SearchMinAbove(a, n, minRow, minCol);
        SearchMaxBelow(a, n, maxRow, maxCol);
        cout << "min above = " << a[minRow][minCol] << endl;
        cout << "max below = " << a[maxRow][maxCol] << endl;

        int S = SumTwo(a, minRow, minCol, maxRow, maxCol);     // сума цих двох елементів
        cout << "S = " << S << endl;

        SwapElements(a, minRow, minCol, maxRow, maxCol);
        Print(a, n);
    }

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void SearchMinAbove(int** a, const int n, int& row, int& col)
{
    row = 0;                            // починаємо з елемента a[0][0] - він завжди над діагоналлю
    col = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i + j < n - 1 && a[i][j] < a[row][col])
            {
                row = i;
                col = j;
            }
}

void SearchMaxBelow(int** a, const int n, int& row, int& col)
{
    row = n - 1;                        // починаємо з елемента a[n-1][n-1] - він завжди під діагоналлю
    col = n - 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i + j > n - 1 && a[i][j] > a[row][col])
            {
                row = i;
                col = j;
            }
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