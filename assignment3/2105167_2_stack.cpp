#include <iostream>
#include "2105167_2_stack.h"
using namespace std;

int main()
{
    stack<int> st;

    while (true)
    {

        int input;
        cin >> input;
        switch (input)
        {
        case 1:
        {
            st.clear();
            st.print();
            break;
        }

        case 2:
        {
            int a;
            cin >> a;
            st.push(a);
            st.print();
            break;
        }

        case 3:
        {
            int a = st.pop();
            cout << a << endl;
            st.print();
            break;
        }

        case 4:
        {
            int len = st.length();
            cout << len << endl;
            st.print();
            break;
        }

        case 5:
        {
            int top_val = st.topvalue();
            cout << top_val << endl;
            st.print();
            break;
        }

        case 6:
        {
            bool is_empty = st.isEmpty();
            if (is_empty)
                cout << "YES\n";
            else
                cout << "NO\n";
            st.print();
            break;
        }

        case 0:
            break;
        }
    }
}