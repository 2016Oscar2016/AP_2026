#include <iostream>
#include <cmath>

using namespace std;

int main()
{   
    const double PI = acos(-1.0);
    double x;   
    double R;   
    double y;   

    cout << "R = "; cin >> R;   // ввід параметра R
    cout << "x = "; cin >> x;   // ввід аргументу x

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

    cout << endl;
    cout << "y = " << y << endl;   // вивід результату

    cin.get();
    return 0;
}