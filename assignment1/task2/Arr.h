#include <iostream>
#include <stdlib.h>
using namespace std;

int capacity, used, cur;
int *ara;

void init(int, int, int);
void insert(int item);
int remove();
void moveToStart();
void moveToEnd();
void prev();
void next();
int length();
int currPos();
void moveToPos(int pos);
int getValue();
void print();

void init(int x, int u = 0, int c = 0)
{
    ara = (int *)malloc(x * sizeof(int));
    capacity = x;
    used = u;
    cur = c;
}

void insert(int item)
{
    if (used == capacity)
    {
        ara = (int *)realloc(ara, 2 * capacity * sizeof(int));
        capacity *= 2;
    }

    for (int i = used + 1; i > cur; i--)
        ara[i] = ara[i - 1];
    ara[cur] = item;
    used++;
}

int remove()
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

void moveToStart()
{
    cur = 0;
}

void moveToEnd()
{
    cur = used - 1;
}

void prev()
{
    if (cur == 0)
    {
        cout << "Can't move left" << endl;
        return;
    }
    cur--;
}

void next()
{
    if (cur == used)
    {
        cout << "Can't move left" << endl;
        return;
    }
    cur++;
}

int length()
{
    return used;
}

int currPos()
{
    return cur;
}

void moveToPos(int pos)
{
    if (pos < 0 || pos > used)
    {
        cout << "Invalid position" << endl;
        return;
    }
    cur = pos;
}

int getValue()
{
    return ara[cur];
}

void print()
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