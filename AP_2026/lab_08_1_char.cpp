#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int ThirdComma(char* s)                 // s = вказівник на початок рядка
{
    int k = 0;                          // k = кількість ком, які вже знайдено
    char* p = s;                        // p = вказівник на кому
    while ((p = strchr(p, ',')) != NULL)
    {
        k++;
        if (k == 3)
            return p - s;               // номер третьої коми
        p++;
    }
    return -1;
}

char* Change(char* s)
{
    char* t = new char[2 * strlen(s) + 1];
    char* p;                            // p = вказівник на кому
    int pos = 0;                        // pos = позиція початку пошуку
    *t = '\0';

    while ((p = strchr(s + pos, ',')) != NULL)
    {
        strncat(t, s + pos, p - s - pos);   // частина рядка до коми
        strcat(t, "**");
        pos = p - s + 1;                // наступний символ після коми
    }
    strcat(t, s + pos);

    return t;
}

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "Third comma index: " << ThirdComma(str) << endl;

    char* dest = Change(str);
    cout << "Modified string: " << dest << endl;

    return 0;
}