#include <iostream>
#include <cstring>
#include "arr.h"
using namespace std;

void request_a_car(LL<int> *list, int y)
{
    for (int i = 1; i <= y; i++)
    {
        if (list[i].length())
        {
            int minpos = 0;
            int minval = 99999999;

            for (list[i].moveToStart(); list[i].currPos() < list[i].length(); list[i].next())
            {
                if (list[i].getValue() < minval)
                {
                    minpos = list[i].currPos();
                    minval = list[i].getValue();
                }
            }

            list[i].moveToPos(minpos);
            list[i].remove();
            return;
        }
    }
    cout << "No car in garage" << endl;
}

void return_car(LL<int> *list, int y, int z, int car)
{
    for (int i = y; i >= 1; i--)
    {
        if (list[i].length() < z)
        {
            int maxpos = 0;
            int maxval = -999999;

            for (list[i].moveToStart(); list[i].currPos() < list[i].length(); list[i].next())
            {
                if (list[i].getValue() > maxval)
                {
                    maxpos = list[i].currPos();
                    maxval = list[i].getValue();
                }
            }

            list[i].moveToPos(maxpos);
            list[i].next();
            list[i].insert(car);
            return;
        }
    }
    cout << "No empty slot in garages" << endl;
}

void print(LL<int> *list, int y)
{
    for (int i = 1; i <= y; i++)
    {
        if (list[i].length())
        {
            for (list[i].moveToStart(); list[i].currPos() < list[i].length(); list[i].next())
                cout << list[i].getValue() << " ";
            cout << endl;
        }
        else
            cout << endl;
    }
}

int main()
{
    int x, y, z;
    cin >> x >> y >> z;

    LL<int> list[y + 1];

    for (int i = 0; i < y; i++)
    {
        int g, n;
        cin >> g >> n;

        for (int i = 0; i < n; i++)
        {
            int number;
            cin >> number;
            list[g].insert(number);
            list[g].next();
        }
    }

    while (true)
    {
        char in[5];
        cin >> in;
        if (strcmp(in, "end") == 0)
            break;

        else if (strcmp(in, "req") == 0)
        {
            request_a_car(list, y);
            print(list, y);
        }

        else if (strcmp(in, "ret") == 0)
        {
            int car;
            cin >> car;
            return_car(list, y, z, car);
            print(list, y);
        }
    }
}