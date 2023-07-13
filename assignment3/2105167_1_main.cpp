#include <iostream>
#include "2105167_1_a_queue.cpp"
// #include "2105167_1_ll_queue.cpp"
using namespace std;

int main()
{
    queue<int> q;

    while (true)
    {
        int in;
        cin >> in;

        switch (in)
        {
        case 1:
        {
            int num;
            cin >> num;
            q.enqueue(num);
            q.print();
            break;
        }

        case 2:
        {
            int num = q.dequeue();
            cout << num << endl;
            q.print();
            break;
        }

        case 3:
        {
            cout << q.length() << endl;
            q.print();
            break;
        }

        case 4:
        {
            int num = q.front();
            cout << num << endl;
            q.print();
            break;
        }

        case 5:
        {
            int num = q.back();
            cout << num << endl;
            q.print();
            break;
        }

        case 6:
        {
            bool empty = q.is_empty();
            cout << (empty ? "true" : "false") << endl;
            q.print();
            break;
        }

        case 7:
        {
            q.clear();
            q.print();
            break;
        }

        case 0:
            break;
        }
    }
}