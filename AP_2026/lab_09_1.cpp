// Lab_9_1.cpp – головний файл проекту: функція main
// e^(x^2) = sum( x^(2n) / n! ) = 1 + x^2 + x^4/2! + x^6/3! + ...
#include <iostream>
#include <math.h>
#include <iomanip>

#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;

using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main()
{
    cout << "x_p = "; cin >> x_p;
    cout << "x_k = "; cin >> x_k;
    cout << "dx  = "; cin >> dx;
    cout << "e   = "; cin >> e;
    cout << endl;

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|   x   |   exp(x^2)   |     S(x)     |    n    |" << endl;
    cout << "-------------------------------------------------" << endl;

    x = x_p;
    while (x <= x_k) {
        sum();                  // виклик процедури обчислення суми

        cout << "| " << setw(5) << setprecision(2) << x << " "
            << "| " << setw(12) << setprecision(6) << exp(x * x) << " "
            << "| " << setw(12) << s << " "
            << "| " << setw(7) << n << " |" << endl;

        x += dx;
    }
    cout << "-------------------------------------------------" << endl;

    cin.get();
    return 0;
}