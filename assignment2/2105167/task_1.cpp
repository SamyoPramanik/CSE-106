#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    cout << "1 for int and 2 for char\n";
    int n;
    cin >> n;

    int chunk, init_size;
    cin >> chunk >> init_size;

    if (n == 1)
    {
        stack<int> st(chunk);

        for (int i = 0; i < init_size; i++)
        {
            int a;
            cin >> a;
            st.push(a);
        }
        st.print();

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
    else
    {
        stack<char> st(chunk);

        for (int i = 0; i < init_size; i++)
        {
            char a;
            cin >> a;
            st.push(a);
        }
        st.print();

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
                char a;
                cin >> a;
                st.push(a);
                st.print();
                break;
            }

            case 3:
            {
                char a = st.pop();
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
                char top_val = st.topvalue();
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
}