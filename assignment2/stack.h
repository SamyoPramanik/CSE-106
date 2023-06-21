#include <iostream>
using namespace std;

template <class x>
class stack
{
    x *st;
    int cnt;
    int capacity;

public:
    stack(int capacity = 2)
    {
        cnt = 0;
        st = (x *)malloc(capacity * sizeof(x));
        this->capacity = capacity;
    }

    ~stack()
    {
        free(st);
        cnt = 0;
        st = (x *)malloc(2 * sizeof(x));
        capacity = 2;
    }

    void push(x val)
    {
        if (cnt >= capacity)
        {
            st = (x *)realloc(st, 2 * capacity * sizeof(x));
            capacity *= 2;
        }
        st[cnt++] = val;
    }

    x pop()
    {
        if (cnt <= 0)
        {
            cout << "stack is empty" << endl;
            return -1;
        }

        return st[--cnt];
    }

    void clear()
    {
        free(st);
        cnt = 0;
        st = malloc(2 * sizeof(x));
        capacity = 2;
    }

    int length()
    {
        return cnt;
    }

    x topvalue()
    {
        return st[cnt - 1];
    }

    bool isEmpty()
    {
        if (cnt)
            return false;
        return true;
    }
};