// Лабораторна робота № 5.5

#include <iostream>

using namespace std;

// b - основа, p - показник степеня, level - рівень поточного виклику,
// depth - глибина рекурсії (вихідний параметр); повертає b^p
int Power(const int b, const int p, const int level, int& depth)
{
    cout << "level = " << level << ", p = " << p << endl;

    if (p == 0)                                 // b^0 = 1
    {
        depth = level;                          // найглибший виклик
        return 1;
    }

    int h = Power(b, p / 2, level + 1, depth);  // h = b^(p/2)

    if (p % 2 == 0)                             // p парне: (b^(p/2))^2
        return h * h;
    else                                        // p непарне: b * (b^(p/2))^2
        return b * h * h;
}

int main()
{
    int b, p, m;
    int depth = 0;
    cout << "b = "; cin >> b;
    cout << "p = "; cin >> p;
    cout << "m = "; cin >> m;

    int r = Power(b, p, 0, depth) % m;          // b^p mod m

    cout << "b^p mod m = " << r << endl;
    cout << "depth = " << depth << endl;

    return 0;
}