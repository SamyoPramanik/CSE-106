#include "2105154_1_a_queue.h"
template <typename x>
class queue1
{
    int rear;
    int frontv;
    int msize;
    Arr<x> arlist;

public:
    queue1()
    {
        rear = 0;
        frontv = 1;
        msize = 15;
        arlist.init();
    }
    void enqueue(x item)
    {

        if ((rear + 2) % msize == frontv)
        {
            msize = msize * 2;
        }
        rear = (rear + 1) % msize;
        arlist.moveToPos(rear);
        arlist.insert(item);
    }
    x front()
    {
        arlist.moveToPos(frontv);
        return arlist.getValue();
    }
    x back()
    {
        arlist.moveToPos(rear);
        return arlist.getValue();
    }
    int length()
    {
        return arlist.length();
    }
    x dequeue()
    {
        if (length() == 0)
        {
            return '#';
        }
        arlist.moveToPos(frontv);
        x item = arlist.remove();
        frontv = (frontv + 1) % msize;
        return item;
    }

    void clear()
    {
        rear = 0;
        frontv = 1;
        arlist.clear();
    }
    bool isempty()
    {
        if (arlist.length() == 0)
        {
            return true;
        }
        return false;
    }
    void show()
    {
        cout << "< ";
        for (int k = frontv; k <= rear; k++)
        {
            arlist.moveToPos(k);
            if (k == rear)
            {
                cout << arlist.getValue() << " ";
            }
            else
            {
                cout << arlist.getValue() << ",";
            }
        }
        cout << ">";
        cout << endl;
    }
};