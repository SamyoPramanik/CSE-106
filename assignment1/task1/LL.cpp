#include <iostream>
#include <new>
using namespace std;

struct node
{
    int val;
    node *next;
};

node *head = NULL;
node *cur = NULL;
node *tail = NULL;
int cnt = 0;
int curpos = 0;

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

void insert(int val)
{
    node *a = new node;
    if (cnt == 0)
    {
        head = tail = a;
        head->val = val;
        head->next = NULL;
        curpos = 0;
    }

    else if (cur == head)
    {
        a->val = val;
        a->next = head;
        head = a;
    }

    // else if (curpos == cnt)
    // {
    //     tail->next = a;
    //     a->val = val;
    //     a->next = NULL;
    //     tail = a;
    // }

    else
    {
        node *i;
        a->val = val;

        for (i = head; i->next != cur; i = i->next)
            ;
        i->next = a;
        a->next = cur;
    }
    cur = a;
    cnt++;
}

int remove()
{
    if (cnt <= 0)
    {
        cerr << "List is empty\n";
        exit(1);
    }

    if (cur == NULL)
    {
        cerr << "at last position\n";
        exit(1);
    }
    int ret;
    if (cur == head)
    {
        ret = cur->val;
        head = cur->next;
        delete cur;
        cur = head;
    }

    else
    {
        ret = cur->val;
        node *
            i;

        for (i = head; i->next != cur; i = i->next)
            ;
        i->next = cur->next;
        node *temp = cur;
        cur = cur->next;
        delete temp;
    }

    cnt--;
    return ret;
}

void moveToStart()
{
    cur = head;
    curpos = 0;
}

void moveToEnd()
{

    moveToPos(cnt);
}

int length()
{
    return cnt;
}

int currPos()
{
    return curpos;
}

int getValue()
{
    if (cnt <= 0)
    {
        cerr << "List is empty\n";
        exit(1);
    }
    return cur->val;
}

void moveToPos(int pos)
{
    if (pos < 0 || pos > cnt)
    {
        cout << "Invalid position\n";
        return;
    }
    if (curpos < pos)
    {
        while (curpos != pos)
            next();
    }

    else if (curpos > pos)
    {
        while (curpos != pos)
            prev();
    }
}

void next()
{
    if (cur == NULL)
    {
        cout << "Already in last position\n";
        return;
    }
    cur = cur->next;
    curpos++;
}

void prev()
{
    if (cur == head)
    {
        cout << "Already in first position\n";
        return;
    }
    node *i;

    for (i = head; i->next != cur; i = i->next)
        ;
    cur = i;
    curpos--;
}

void print()
{
    cout << "< ";
    node *i;

    for (i = head; i != NULL; i = i->next)
    {
        if (i == cur)
            cout << "|";
        cout << i->val << " ";
    }

    if (curpos == cnt)
        cout << "|";
    cout << ">\n";
}

int main()
{
    int k, x;
    cin >> k >> x;

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
