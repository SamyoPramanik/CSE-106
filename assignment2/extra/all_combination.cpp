#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>
using namespace std;

char op[] = "d+-*/()";
char str[10];

void combi(int at, int max)
{
    if (at == max)
    {
        str[at] = '\0';

        for (int i = 0; i < strlen(str); i++)
        {
            srand(time(NULL));
            if (str[i] == 'd')
                str[i] = rand() % 10 + '0';
        }

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
    cout << "exit" << endl;
}