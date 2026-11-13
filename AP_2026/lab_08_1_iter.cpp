// Дано літерний рядок, який містить послідовність символів s0, ..., sn, ... .
// Відомо, що серед цих символів є щонайменше три коми.
// 1. Знайти число i таке, що s[i] – третя за порядком кома.
// 2. Замінити кожну кому парою зірочок "**".

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int ThirdComma(char* s)                 // s = вказівник на початок рядка
{
    int k = 0;                          // k = кількість ком, які вже знайдено
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == ',')
        {
            k++;
            if (k == 3)
                return i;               // i = номер третьої коми
        }
    return -1;
}

char* Change(char* s)
{
    char* d = new char[2 * strlen(s) + 1];
    char* t = d;                        // t = вказівник на поточний символ нового рядка

    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == ',')
        {
            *t++ = '*';
            *t++ = '*';
        }
        else
            *t++ = s[i];
    *t = '\0';

    return d;
}

int main()
{
    string line;                        // рядок будь-якої довжини

    cout << "Enter string:" << endl;
    getline(cin, line);

    char* str = new char[line.length() + 1];
    strcpy(str, line.c_str());

    cout << "Third comma index: " << ThirdComma(str) << endl;

    char* dest = Change(str);
    cout << "Modified string: " << dest << endl;

    return 0;
}