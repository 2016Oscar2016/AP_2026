// Lab_05_4.cpp
// Пастернак Олександр
// Лабораторна робота № 5.4
// Обчислення сум та добутків за допомогою рекурсії
// Варіант 23

#include <iostream>
#include <cmath>

using namespace std;

// K, N - межі суми (ітераційний спосіб)
double S0(const int K, const int N)
{
    double s = 0;
    for (int i = K; i <= N; i++)
        s += (cos(i / 2.) + sin(2. * i)) / (1 + sin(cos(i)));
    return s;
}

// i - поточний номер доданка (рекурсивний спуск, i зростає)
double S1(const int K, const int N, const int i)
{
    if (i > N)
        return 0;
    else
        return (cos(i / 2.) + sin(2. * i)) / (1 + sin(cos(i))) + S1(K, N, i + 1);
}

// рекурсивний спуск, i спадає
double S2(const int K, const int N, const int i)
{
    if (i < K)
        return 0;
    else
        return (cos(i / 2.) + sin(2. * i)) / (1 + sin(cos(i))) + S2(K, N, i - 1);
}

// t - накопичена сума (рекурсивний підйом, i зростає)
double S3(const int K, const int N, const int i, double t)
{
    t = t + (cos(i / 2.) + sin(2. * i)) / (1 + sin(cos(i)));
    if (i >= N)
        return t;
    else
        return S3(K, N, i + 1, t);
}

// рекурсивний підйом, i спадає
double S4(const int K, const int N, const int i, double t)
{
    t = t + (cos(i / 2.) + sin(2. * i)) / (1 + sin(cos(i)));
    if (i <= K)
        return t;
    else
        return S4(K, N, i - 1, t);
}

int main()
{
    const int K = 3;   // нижня межа суми за умовою
    int N;
    cout << "K = " << K << endl;
    cout << "N = "; cin >> N;

    if (N < K)
    {
        cout << "N >= " << K << endl;
        return 1;
    }

    cout << "(iter)        S0 = " << S0(K, N) << endl;
    cout << "(rec up ++)   S1 = " << S1(K, N, K) << endl;
    cout << "(rec up --)   S2 = " << S2(K, N, N) << endl;
    cout << "(rec down ++) S3 = " << S3(K, N, K, 0) << endl;
    cout << "(rec down --) S4 = " << S4(K, N, N, 0) << endl;

    return 0;
}