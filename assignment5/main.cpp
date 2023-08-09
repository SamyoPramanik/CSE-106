#include <iostream>
#include "heap.h"
using namespace std;

int main()
{
    Heap<int> hp;
    int choice;

    while (true)
    {
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int num;
            cin >> num;
            hp.insert(num);
            break;
        }

        case 2:
        {
            int maxNum = hp.findMax();
            cout << "Max: " << maxNum << endl;
            break;
        }

        case 3:
        {
            cout << "Max: " << hp.extractMax() << " has been extracted." << endl;
            break;
        }

        case 4:
        {
            int i, newKey;
            cin >> i >> newKey;
            hp.increaseKey(i, newKey);
            break;
        }
        case 5:
        {
            int i, newKey;
            cin >> i >> newKey;
            hp.decreaseKey(i, newKey);
            break;
        }
        case 6:
        {
            cout << "No of elements: " << hp.length() << endl;
            hp.print();
            break;
        }
        case 7:
            hp.sort();
            cout << "No of elements: " << hp.length() << endl;
            hp.print();
            return 0;
        }
    }
}