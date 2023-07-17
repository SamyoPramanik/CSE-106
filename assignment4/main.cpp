#include <iostream>
#include <string>
#include "BST.h"
using namespace std;

int main()
{
    BST<int> tree;
    char op;

    while (cin >> op)
    {
        // cin >> op;

        switch (op)
        {
        case 'I':
        {
            int num;
            cin >> num;
            tree.insert(num);
            tree.print();
            break;
        }

        case 'D':
        {
            int num;
            cin >> num;
            tree.remove(num);
            tree.print();
            break;
        }

        case 'F':
        {
            int num;
            cin >> num;
            if (tree.find(num))
                cout << "found\n";
            else
                cout << "not found\n";
            break;
        }

        case 'T':
        {
            string type;
            cin >> type;
            tree.traverse(type);
            break;
        }

        default:
            break;
        }
    }
}