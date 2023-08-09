#ifndef HEAP
#define HEAP
#include <iostream>
#include <new>
using namespace std;

template <class T>
class Heap
{
private:
    T *ara;
    int maxSize = 2;
    int size;

    void relocate_down(int start, int end = -1)
    {
        if (end == -1)
            end = this->size;

        int highest = start;
        int left = start * 2;
        int right = start * 2 + 1;

        if (left <= end && ara[left] > ara[start])
            highest = left;

        if (right <= end && ara[right] > ara[highest])
            highest = right;

        if (highest != start)
        {
            swap(start, highest);
            relocate_down(highest, end);
        }
    }

    void relocate_up(int i)
    {
        while (i > 1)
        {
            if (ara[i] > ara[i / 2])
            {
                swap(i, i / 2);
                i /= 2;
            }
            else
                break;
        }
    }

    void swap(int i, int j)
    {
        T temp = ara[i];
        ara[i] = ara[j];
        ara[j] = temp;
    }

public:
    Heap()
    {
        this->maxSize = 2;
        ara = (T *)malloc(maxSize * sizeof(T));
        int size = 0;
    }

    void insert(T x)
    {
        if (size >= maxSize - 1)
        {

            maxSize *= 2;
            ara = (T *)realloc(ara, maxSize * sizeof(T));
            // T *temp = new T[maxSize];
            // for (int i = 0; i <= size; i++)
            // {
            //     temp[i] = ara[i];
            // }
            // delete[] ara;
            // ara = temp;
        }

        ara[++size] = x;
        relocate_up(size);
    }

    T findMax()
    {
        return ara[1];
    }

    T extractMax()
    {
        T ret = ara[1];
        swap(1, size);
        size--;

        relocate_down(1);

        return ret;
    }

    void increaseKey(int i, T newkey)
    {
        if (newkey < ara[i])
        {
            cout << "New key is not larger than the previous key" << endl;
            return;
        }

        ara[i] = newkey;
        relocate_up(i);
        cout << "Key increased!" << endl;
    }

    void decreaseKey(int i, T newkey)
    {
        if (newkey > ara[i])
        {
            cout << "New key is not smaller than the previous key" << endl;
            return;
        }

        ara[i] = newkey;
        relocate_down(i);
        cout << "Key decreased!" << endl;
    }

    void print(int start = 1, int total = 1)
    {
        if (start > size)
            return;

        for (int i = start, j = 0; i <= size && j < total; i++, j++)
            cout << ara[i] << "\t";
        cout << endl;

        if (start * 2 <= size)
            print(start * 2, total * 2);
    }

    int length()
    {
        return size;
    }

    void sort()
    {
        for (int i = size; i > 1; i--)
        {
            swap(1, i);
            relocate_down(1, i - 1);
        }
    }
};

#endif