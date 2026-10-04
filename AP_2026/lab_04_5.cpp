// Lab_04_5.cpp
// Пастернак Олександр
// Лабораторна робота № 4.5
// Цикли.
// Варіант 0.23

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int main()
{
    double R, x, y;

    srand((unsigned)time(NULL));

    cout << "R = "; cin >> R;

    // 1 спосіб: координати з клавіатури
    for (int i = 0; i < 10; i++)
    {
        cout << "x = "; cin >> x;
        cout << "y = "; cin >> y;

        if ((x >= -R && x <= R && y >= -R && y <= R)                // у квадраті
            && ((x + R) * (x + R) + (y - R) * (y - R) >= R * R)     // поза колом 1, центр (-R; R)
            && ((x - R) * (x - R) + (y + R) * (y + R) >= R * R))    // поза колом 2, центр (R; -R)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    cout << endl << fixed;

    // 2 спосіб: випадкові координати з [-2R; 2R]
    for (int i = 0; i < 10; i++)
    {
        x = 4 * R * rand() / RAND_MAX - 2 * R;                      // x з [-2R; 2R]; x = (4 * R) * [0; 1] - 2 * R = [0; 4R] - 2R = [-2R; 2R]
        y = 4 * R * rand() / RAND_MAX - 2 * R;                      // y з [-2R; 2R]

        if ((x >= -R && x <= R && y >= -R && y <= R)                // у квадраті
            && ((x + R) * (x + R) + (y - R) * (y - R) >= R * R)     // поза колом 1, центр (-R; R)
            && ((x - R) * (x - R) + (y + R) * (y + R) >= R * R))    // поза колом 2, центр (R; -R)
            cout << setw(8) << setprecision(4) << x
            << setw(8) << setprecision(4) << y << " " << "yes" << endl;
        else
            cout << setw(8) << setprecision(4) << x
            << setw(8) << setprecision(4) << y << " " << "no" << endl;
    }

    return 0;
}