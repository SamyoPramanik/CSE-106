#include <iostream>
using namespace std;
template <typename x>
class Arr
{
public:
    int currentindex;
    x *arr;
    int currentsize;
    int maxsize;
    Arr() {}
    void init(int listsize = 15)
    {
        maxsize = listsize;
        currentindex = 1;
        currentsize = 0;
        arr = new x[maxsize];
    }
    ~Arr() { delete[] arr; }
    void insert(x value)
    {
        if (currentsize == maxsize)
        {
            maxsize = 2 * maxsize;
            x *arra = new x[maxsize];
            for (int i = 0; i < currentsize; i++)
                arra[i] = arr[i];
            delete[] arr;
            arr = arra;
        }
        for (int i = currentsize; i > currentindex; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[currentindex] = value;
        currentsize++;
        return;
    }
    x remove()
    {
        if (currentsize != 0)
        {
            currentsize--;
            return getValue();
        }
        else if (currentsize == 0)
        {
            cout << "no elements!" << endl;
        }
        else
        {
            if (currentsize == 0 || currentindex == currentsize)
            {
                cout << "no elements to remove" << endl;
                return 0;
            }
            if (currentindex == currentsize - 1)
            {
                currentindex--;
                currentsize--;
                return arr[currentsize];
            }
            x returnvalue = arr[currentindex];
            for (int i = currentindex; i <= currentsize - 2; i++)
                arr[i] = arr[i + 1];
            currentsize--;
            return returnvalue;
        }
    }
    void moveToStart()
    {
        currentindex = 0;
        return;
    }
    void moveToEnd()
    {
        currentindex = currentsize - 1;
        return;
    }
    void prev()
    {
        if (currentindex == 0)
        {
            return;
        }
        currentindex--;
    }
    void next()
    {
        if (currentindex <= currentsize)
        {
            currentindex++;
        }
    }
    int length() { return currentsize; }
    int curPos() { return currentindex; }
    void moveToPos(int index) { currentindex = index; }
    x getValue()
    {

        return arr[currentindex];
    }
    void show()
    {
        if (currentsize != 0)
        {
            cout << "< ";
            for (int j = 0; j < currentindex; j++)
                cout << arr[j] << ", ";
            for (int j = currentindex; j < (currentsize - 1); j++)
            {
                cout << arr[j] << ", ";
            }
            if (currentindex != currentsize)
            {
                cout << arr[currentsize - 1] << ">" << endl;
            }
            else
            {
                cout << ">" << endl;
            }
        }
    }
    void clear()
    {
        while (currentsize != 0)
        {
            moveToStart();
            remove();
        }
        init(15);
    }
    void append(x item)
    {
        moveToEnd();
        next();
        insert(item);
    }
};
