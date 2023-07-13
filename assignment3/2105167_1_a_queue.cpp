#include <iostream>
#include "2105167_1_a_queue.h"
using namespace std;

template <class T>
class queue
{
    LL<T> list;
    int start;
    int rear;
    int maxCapacity;
    int size;

    void resize()
    {
        LL<T> list;
    }

public:
    queue(int c = 5)
    {
        start = 0;
        rear = -1;
        maxCapacity = c;
        size = 0;
        for (int i = 0; i < maxCapacity; i++)
            list.insert(0);
    }

    void enqueue(T it)
    {
        if (size == maxCapacity)
        {
            // cout << "queue is full" << endl;
            // return;
            maxCapacity++;
            size++;
            list.moveToPos((rear + 1) % maxCapacity);
            list.insert(it);
            if (start == rear + 1)
                start = (start + 1) % maxCapacity;
            rear = (rear + 1) % maxCapacity;
            return;
        }
        size++;
        rear = (rear + 1) % maxCapacity;
        list.moveToPos(rear);
        list.remove();
        list.insert(it);
    }

    T dequeue()
    {
        if (size == 0)
            return -1;

        list.moveToPos(start);
        T ret = list.getValue();
        start = (start + 1) % maxCapacity;
        size--;
        return ret;
    }

    int length()
    {
        return size;
    }

    T front()
    {
        list.moveToPos(start);
        return list.getValue();
    }

    T back()
    {
        list.moveToPos(rear);
        return list.getValue();
    }

    bool is_empty()
    {
        return size ? true : false;
    }

    void clear()
    {
        list.moveToStart();
        while (list.length())
            list.remove();
    }

    void print()
    {
        cout << "< ";
        for (int i = start, j = 0; j < size; j++)
        {
            list.moveToPos((start + j) % maxCapacity);
            cout << list.getValue() << " ";
        }
        cout << ">\n";
    }
};