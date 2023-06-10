#include <iostream>
#include <stdlib.h>
using namespace std;

template <class x>
class LL
{
    int capacity, used, cur;
    x *ara;

public:
    LL(int cap = 2, int u = 0, int c = 0)
    {
        ara = (int *)malloc(cap * sizeof(int));
        capacity = cap;
        used = u;
        cur = c;
    }

    void insert(int item);
    x remove();
    void moveToStart();
    void moveToEnd();
    void prev();
    void next();
    int length();
    x currPos();
    void moveToPos(int pos);
    x getValue();
    void print();
};

template <class x>
void LL<x>::insert(int item)
{
    if (used == capacity)
        ara = (int *)realloc(ara, 2 * capacity * sizeof(int));

    for (int i = used + 1; i > cur; i--)
        ara[i] = ara[i - 1];
    ara[cur] = item;
    used++;
}

template <class x>
x LL<x>::remove()
{
    if (cur >= used)
    {
        cerr << "nothing to remove" << endl;
        exit(1);
    }

    if (used == 0)
    {
        cerr << "empty array" << endl;
        exit(1);
    }

    int ret = ara[cur];
    for (int i = cur; i < used; i++)
        ara[i] = ara[i + 1];
    used--;
    return ret;
}

template <class x>
void LL<x>::moveToStart()
{
    cur = 0;
}

template <class x>
void LL<x>::moveToEnd()
{
    cur = used - 1;
}

template <class x>
void LL<x>::prev()
{
    if (cur == 0)
    {
        cout << "Can't move left" << endl;
        return;
    }
    cur--;
}

template <class x>
void LL<x>::next()
{
    if (cur == used)
    {
        cout << "Can't move left" << endl;
        return;
    }
    cur++;
}

template <class x>
int LL<x>::length()
{
    return used;
}

template <class x>
x LL<x>::currPos()
{
    return cur;
}

template <class x>
void LL<x>::moveToPos(int pos)
{
    if (pos < 0 || pos > used)
    {
        cout << "Invalid position" << endl;
        return;
    }
    cur = pos;
}

template <class x>
x LL<x>::getValue()
{
    return ara[cur];
}

template <class x>
void LL<x>::print()
{
    cout << "<";
    for (int i = 0; i < used; i++)
    {
        if (cur == i)
            cout << "| ";

        cout << ara[i] << " ";
    }
    if (cur == used)
        cout << "| ";
    cout << ">"
         << "\n";
}
