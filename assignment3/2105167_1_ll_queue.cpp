#include <iostream>
#include "2105167_1_ll_queue.h"
using namespace std;

template <class T>
class queue
{
    LL<T> list;

public:
    void enqueue(T it)
    {
        list.moveToEnd();
        list.next();
        list.insert(it);
    }

    T dequeue()
    {
        list.moveToStart();
        T temp = list.remove();
        return temp;
    }

    int length()
    {
        return list.length();
    }

    T front()
    {
        list.moveToStart();
        return list.getValue();
    }

    T back()
    {
        list.moveToEnd();
        return list.getValue();
    }

    bool is_empty()
    {
        return list.length() ? true : false;
    }

    void clear()
    {
        list.moveToStart();
        while (list.length())
            list.remove();
    }

    void print()
    {
        list.print();
    }
};