#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


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
            *t++ = '*';               //[*][ ][ ][ ]
            *t++ = '*';               //[*][*][ ][ ]
        }
        else
            *t++ = s[i];
    *t = '\0';

    return d;
}

int main()
{
    char str[101];

    cout << "enter string:" << endl;
    cin.getline(str, 100);

    cout << "3 comma index: " << ThirdComma(str) << endl;

    char* dest = Change(str);
    cout << "new string: " << dest << endl;

    return 0;
}








// ===== Введення рядків =====

// cin.getline(s, n)  – читає з клавіатури рядок ЗІ ПРОБІЛАМИ у масив char[]
//                      (до n-1 символів, в кінець сам дописує '\0')
//   char s[101];
//   cin.getline(s, 100);        // ввели "ab, cd"  →  s = "ab, cd"

// getline(cin, s)    – те саме, але для рядка типу string (довжина необмежена)
//   string s;
//   getline(cin, s);            // ввели "ab, cd"  →  s = "ab, cd"

// ===== Рядки char[] (#include <cstring>) =====

// strlen(s)          – довжина рядка s (без '\0')
//   char s[] = "a,b";
//   strlen(s)                   // 3

// strcpy(d, s)       – копіює рядок s у d (разом із '\0')
//   char d[20];
//   strcpy(d, "abc");           // d = "abc"

// strncpy(d, s, n)   – копіює не більше n символів s у d;
//                      '\0' сам НЕ дописує, його треба дописати вручну
//   char d[20];
//   strncpy(d, "abcdef", 3);
//   d[3] = '\0';                // d = "abc"

// strcat(d, s)       – дописує рядок s в кінець d
//   char d[20] = "ab";
//   strcat(d, "cd");            // d = "abcd"

// strncat(d, s, n)   – дописує не більше n символів s в кінець d (і дописує '\0')
//   char d[20] = "ab";
//   strncat(d, "cdef", 2);      // d = "abcd"

// strcmp(s1, s2)     – порівнює рядки: 0 – рівні, <0 – s1 менший, >0 – s1 більший
//   strcmp("abc", "abc")        // 0
//   strcmp("abc", "abd")        // менше нуля ("abc" менший)

// strncmp(s1, s2, n) – порівнює лише перші n символів
//   strncmp("abcd", "abxy", 2)  // 0 (перші 2 символи "ab" однакові)

// ===== Пошук у char[] =====

// strchr(s, c)       – вказівник на ПЕРШЕ входження символу c (або NULL)
//   char s[] = "a,b,c";
//   char* p = strchr(s, ',');   // p вказує на першу кому
//   p - s                       // 1 (номер коми в рядку)

// strstr(s, sub)     – вказівник на перше входження підрядка sub (або NULL)
//   strstr("abcabc", "ca")      // вказує на символ з номером 2

// ===== Рядки string (#include <string>) =====

// s.find(x, pos)     – позиція першого входження x від позиції pos;
//                      якщо немає – string::npos
//   string s = "a,b,c";
//   s.find(',', 0)              // 1
//   s.find(',', 2)              // 3

// s.replace(pos, len, x) – замінює len символів з позиції pos на рядок x
//   string s = "a,b";
//   s.replace(1, 1, "**");      // s = "a**b"

// s.length()         – довжина рядка
//   string s = "a,b";
//   s.length()                  // 3