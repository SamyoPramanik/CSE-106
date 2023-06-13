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
    if (used >= capacity)
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
    if (used <= 0)
        cur = 0;

    else
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
        cout << "Can't move right" << endl;
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

int main()
{
    int k, x;
    cin >> k >> x;

    init(x);

    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        insert(a);
    }

    print();

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
            int a;
            cin >> a;
            insert(a);
            print();
            break;
        }

        case 2:
        {
            int n = remove();
            cout << n << "\n";
            print();
            break;
        }
        case 3:
        {
            moveToStart();
            print();
            break;
        }
        case 4:
        {
            moveToEnd();
            print();
            break;
        }
        case 5:
        {
            prev();
            print();
            break;
        }
        case 6:
        {
            next();
            print();
            break;
        }
        case 7:
        {
            int len = length();
            cout << len << "\n";
            print();
            break;
        }
        case 8:
        {
            int pos = currPos();
            cout << pos << "\n";
            print();
            break;
        }
        case 9:
        {
            int pos;
            cin >> pos;
            moveToPos(pos);
            print();
            break;
        }
        case 10:
        {
            int val = getValue();
            cout << val << "\n";
            print();
            break;
        }
        }
    }
}
