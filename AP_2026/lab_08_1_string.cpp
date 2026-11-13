
#include <iostream>
#include <string>

using namespace std;

int ThirdComma(const string s)
{
    int k = 0;                          // k = кількість ком, які вже знайдено
    size_t pos = 0;                     // pos = позиція початку пошуку
    while ((pos = s.find(',', pos)) != string::npos)
    {
        k++;
        if (k == 3)
            return pos;                 // номер третьої коми
        pos++;
    }
    return -1;
}

string Change(string& s)
{
    size_t pos = 0;
    while ((pos = s.find(',', pos)) != string::npos)
    {
        s.replace(pos, 1, "**");
        pos += 2;                       // пропускаємо вставлені зірочки
    }

    return s;
}

int main()
{
    string str;

    cout << "Enter string:" << endl;
    getline(cin, str);

    cout << "Third comma index: " << ThirdComma(str) << endl;

    string dest = Change(str);

    cout << "Modified string (result): " << dest << endl;

    return 0;
}