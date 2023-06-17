#include <iostream>
#include "ll.h"
using namespace std;

LL<int> list;

void clear()
{
    list.moveToStart();
    while (list.length())
        int a = list.remove();
}

void append(int item)
{
    if (list.length() == 0)
    {
        list.insert(item);
        return;
    }

    int cpos = list.currPos();
    list.moveToPos(list.length());
    list.insert(item);
    list.moveToPos(cpos);
}

int search(int item)
{
    int cpos = list.currPos();

    for (list.moveToStart(); list.currPos() < list.length(); list.next())
    {
        if (list.getValue() == item)
        {
            int pos = list.currPos();
            list.moveToPos(cpos);
            return pos;
        }
    }

    list.moveToPos(cpos);
    return -1;
}

int main()
{
    // freopen("../2.txt", "r", stdin);
    while (1)
    {
        int in;
        cin >> in;
        if (in == 0)
            break;

        switch (in)
        {
        case 1:
        {
            clear();
            list.print();
            break;
        }

        case 2:
        {
            int a;
            cin >> a;
            append(a);
            list.print();
            break;
        }
        case 3:
        {
            int item;
            cin >> item;
            int idx = search(item);
            cout << idx << "\n";
            list.print();
            break;
        }
        }
    }
}
