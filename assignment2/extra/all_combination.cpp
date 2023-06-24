#include <iostream>
#include <cstring>
using namespace std;

char op[] = "2+-*/()";
char str[10];

void combi(int at, int max)
{
    if (at == max)
    {
        str[at] = '\0';
        cout << str;
        cout << "\n";
        return;
    }
    for (int i = 0; i < strlen(op); i++)
    {
        str[at] = op[i];
        combi(at + 1, max);
    }
}

int main()
{
    freopen("combination.txt", "w", stdout);

    for (int i = 0; i <= 7; i++)
        combi(0, i);
}