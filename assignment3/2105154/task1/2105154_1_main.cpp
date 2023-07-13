#include "2105154_1_a_queue.cpp"
// #include "2105154_1_ll_queue.cpp"
int main()
{
    queue1<double> q; // data type changes
    int Q;
    double p; // data type changes
    while (1)
    {
        cin >> Q;
        if (Q == 0)
        {
            break;
        }
        else if (Q == 1)
        {
            cin >> p;
            q.enqueue(p);
            q.show();
        }
        else if (Q == 2)
        {
            double ret = q.dequeue(); // data type dependent
            q.show();
            cout << ret << endl;
        }
        else if (Q == 3)
        {
            q.show();
            cout << q.length() << endl;
        }
        else if (Q == 4)
        {
            q.show();
            cout << q.front() << endl;
        }
        else if (Q == 5)
        {
            q.show();
            cout << q.back() << endl;
            ;
        }
        else if (Q == 6)
        {
            q.show();
            cout << q.isempty() << endl;
        }
        else if (Q == 7)
        {
            q.clear();
            q.show();
        }
    }
}