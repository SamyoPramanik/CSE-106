#include <iostream>
#include "ll.h"
using namespace std;

int main()
{
    int k, x;
    cin >> k >> x;

    LL<string> list;

    for (int i = 0; i < k; i++)
    {
        string a;
        cin >> a;
        list.insert(a);
    }

    list.print();

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
            string a;
            cin >> a;
            list.insert(a);
            list.print();
            break;
        }

        case 2:
        {
            string n = list.remove();
            cout << n << "\n";
            list.print();
            break;
        }
        case 3:
        {
            list.moveToStart();
            list.print();
            break;
        }
        case 4:
        {
            list.moveToEnd();
            list.print();
            break;
        }
        case 5:
        {
            list.prev();
            list.print();
            break;
        }
        case 6:
        {
            list.next();
            list.print();
            break;
        }
        case 7:
        {
            int len = list.length();
            cout << len << "\n";
            list.print();
            break;
        }
        case 8:
        {
            int pos = list.currPos();
            cout << pos << "\n";
            list.print();
            break;
        }
        case 9:
        {
            int pos;
            cin >> pos;
            list.moveToPos(pos);
            list.print();
            break;
        }
        case 10:
        {
            string val = list.getValue();
            cout << val << "\n";
            list.print();
            break;
        }
        }
    }
}
