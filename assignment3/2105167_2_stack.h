#include <iostream>
#include "2105167_1_ll_queue.h"
using namespace std;

template <class T>
class stack
{
    queue<T> q1;
    queue<T> q2;

public:
    void push(T it)
    {
        q1.enqueue(it);
    }

    T pop()
    {
        while (q1.length() > 1)
            q2.enqueue(q1.dequeue());

        T ret = q1.dequeue();
        while (q2.length())
            q1.enqueue(q2.dequeue());

        return ret;
    }

    int length()
    {
        return q1.length();
    }

    T topvalue()
    {
        return q1.back();
    }
    bool isEmpty()
    {
        return q1.is_empty();
    }

    void clear()
    {
        q1.clear();
        q2.clear();
    }

    void print()
    {
        q1.print();
    }
};