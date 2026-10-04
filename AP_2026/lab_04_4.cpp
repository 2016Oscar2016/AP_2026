// Lab_04_4.cpp
// Пастернак Олександр
// Лабораторна робота № 4.4
// Цикли.
// Варіант 0.23
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    const double PI = acos(-1.0);
    double R, x, xp, xk, dx, y;

    cout << "R = "; cin >> R;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;

    cout << fixed;
    cout << "          y(x)" << endl;
    cout << "-------------------------" << endl;
    cout << "|" << setw(8) << "x" << " |" << setw(12) << "y" << " |" << endl;
    cout << "-------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        if (x <= -7 - R)
            // інтервал (-inf; -7-R]
            y = R;
        else
            if (x <= -7 + R)
                // інтервал (-7-R; -7+R]
                // з центром (-7, R) і радіусом R)
                y = R - sqrt(R * R - (x + 7) * (x + 7));
            else
                if (x <= -4)
                    // інтервал (-7+R; -4]
                    y = R;
                else
                    if (x <= 0)
                        // інтервал (-4; 0]; y = R - Rx/4 - R
                        y = -R * x / 4;
                    else
                        if (x <= PI)
                            // інтервал (0; π]
                            y = sin(x);
                        else
                            // інтервал (π; +inf)
                            y = x - PI;

        cout << "|" << setw(8) << setprecision(2) << x
            << " |" << setw(12) << setprecision(3) << y << " |" << endl;

        x += dx;
    }

    cout << "-------------------------" << endl;

    return 0;
}