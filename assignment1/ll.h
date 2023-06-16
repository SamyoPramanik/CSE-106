#include <iostream>
#include <new>
using namespace std;

template <class x>
class node
{
public:
    x val;
    node<x> *next;
};

template <class x>
class LL
{
    node<x> *head = NULL;
    node<x> *cur = NULL;
    node<x> *tail = NULL;
    int cnt = 0;
    int curpos = 0;

public:
    // void init(int, int, int);
    void insert(x item);
    x remove();
    void moveToStart();
    void moveToEnd();
    void prev();
    void next();
    int length();
    int currPos();
    void moveToPos(int pos);
    x getValue();
    void print();
};

template <class x>
void LL<x>::insert(x val)
{
    node<x> *a = new node<x>;
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
        node<x> *i;
        a->val = val;

        for (i = head; i->next != cur; i = i->next)
            ;
        i->next = a;
        a->next = cur;
    }
    cur = a;
    cnt++;
}

template <class x>
x LL<x>::remove()
{
    if (cnt <= 0)
    {
        cerr << "List is empty\n";
        return -1;
    }

    if (cur == NULL)
    {
        cerr << "at last position\n";
        return -1;
    }
    x ret;
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
        node<x> *i;

        for (i = head; i->next != cur; i = i->next)
            ;
        i->next = cur->next;
        node<x> *temp = cur;
        cur = cur->next;
        delete temp;
    }

    cnt--;
    return ret;
}

template <class x>
void LL<x>::moveToStart()
{
    cur = head;
    curpos = 0;
}

template <class x>
void LL<x>::moveToEnd()
{
    if (cnt == 0)
        return;

    moveToPos(cnt);
}

template <class x>
int LL<x>::length()
{
    return cnt;
}

template <class x>
int LL<x>::currPos()
{
    return curpos;
}

template <class x>
x LL<x>::getValue()
{
    if (cnt <= 0)
    {
        cerr << "List is empty\n";
        exit(1);
    }
    return cur->val;
}

template <class x>
void LL<x>::moveToPos(int pos)
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

template <class x>
void LL<x>::next()
{
    if (cnt == 0)
        return;
    if (cur == NULL)
    {
        cout << "Already in last position\n";
        return;
    }
    cur = cur->next;
    curpos++;
}

template <class x>
void LL<x>::prev()
{
    if (cur == head)
    {
        cout << "Already in first position\n";
        return;
    }
    node<x> *i;

    for (i = head; i->next != cur; i = i->next)
        ;
    cur = i;
    curpos--;
}

template <class x>
void LL<x>::print()
{
    cout << "< ";
    node<x> *i;

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
