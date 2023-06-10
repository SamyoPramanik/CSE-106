#include <iostream>
#include "LL.h"
using namespace std;

void clear()
{
    moveToStart();
    while (length())
        int a = remove();
}

void append(int item)
{
    if (length() == 0)
    {
        insert(item);
        return;
    }

    int cpos = currPos();
    moveToEnd();
    insert(item);
    moveToPos(cpos);
}

int search(int item)
{
    int cpos = currPos();

    for (moveToStart(); currPos() < length(); next())
    {
        if (getValue() == item)
        {
            int pos = currPos();
            moveToPos(cpos);
            return pos;
        }
    }

    moveToPos(cpos);
    return -1;
}

int main()
{
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
            print();
            break;
        }

        case 2:
        {
            int a;
            cin >> a;
            append(a);
            print();
            break;
        }
        case 3:
        {
            int item;
            cin >> item;
            int idx = search(item);
            cout << idx << "\n";
            print();
            break;
        }
        }
    }
}
