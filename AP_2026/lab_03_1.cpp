// Lab_03_1.cpp
// Пастернак Олександр
// Лабораторна робота № 3.1
// Розгалуження, задане формулою: функція однієї змінної.
// Варіант 0.23

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x; // вхідний параметр
	double y; // результат обчислення виразу
	double A; // проміжний результат - функціонально стала частина виразу
	double B; // проміжний результат - функціонально змінна частина виразу
	cout << "x = "; cin >> x;

	A = x * x + sin(4 * x / 3);
	// спосіб 1: розгалуження в скороченій формі
	if (x < -5)
		B = cos(x) / sin(x);          // ctg x
	if (x >= -5 && x <= 0)
		B = 4 - x * x / 2;
	if (x > 0)
		B = log10(x * x) - 4 * x / 3;       // lg x^2

	y = A + B;
	cout << endl;
	cout << "1) y = " << y << endl;
	// спосіб 2: розгалуження в повній формі
	if (x < -5)
		B = cos(x) / sin(x);
	else
		if (x <= 0)
			B = 4 - x * x / 2;
		else
			B = log10(x * x) - 4 * x / 3;

	y = A + B;

	cout << "2) y = " << y << endl;

	cin.get();
	return 0;
}
