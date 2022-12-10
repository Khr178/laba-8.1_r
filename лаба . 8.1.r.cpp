// лаба . 8.1.r.cpp 
// Дано літерний рядок, який містить послідовність символів s0, …, sn, … .
// 1. Вияснити, чи є серед цих символів всі букви, що входять в слово “while”.
// 2. Замінити кожну групу букв “while” парою зірочок “ * *”.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int Count(char* str, int i)
{
    if (strlen(str) < 2)
        return 0;
    if (str[i] == 'w' && str[i + 1] == 'h' && str[i + 2] == 'i' && str[i + 3] == 'l' && str[i + 4] == 'e')
        return 1 + Count(str, i + 1);
    else
        return Count(str, i + 1);

    return 0;
} char* Change(char* dest, char* str, char* t, int i)
{
    if (str[i + 1] != 0)
    {
        if (str[i] == 'w' && str[i + 1] == 'h' && str[i + 2] == 'i' && str[i + 3] == 'l' && str[i + 4] == 'e')
        {
            strcat_s(t, strlen(str), "**");
            return Change(dest, str, t + 2, i + 5);
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
            return Change(dest, str, t, i);
        }
    }
    *t++ = str[i++];
    *t++ = str[i++];
    *t = '\0';
    //strcpy(str, tmp);
    return dest;
}
int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    int r = Count(str, 0);
    if (r > 0)
    {
        cout << "yes" << endl;
    }
    else
        cout << "no" << endl;
    char* dest1 = new char[151];
    dest1[0] = '\0';
    char* dest2;
    dest2 = Change(dest1, str, dest1, 0);
    cout << "Modified string (param):" << str << endl;
    cout << "Modified string (result):" << dest1 << endl;
    return 0;
}