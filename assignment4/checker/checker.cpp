#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string out_files[] = {"out_1.txt", "out_2.txt", "out_3.txt"};
    string ans_files[] = {"ans_1.txt", "ans_2.txt", "ans_3.txt"};

    int t = 1;

    for (int i = 0; i < 3; i++)
    {
        ifstream out(out_files[i]);
        ifstream ans(ans_files[i]);
        string ans_line, out_line;

        while (getline(ans, ans_line))
        {
            getline(out, out_line);
            if (ans_line != out_line)
            {
                cout << "Test " << t << " failed\n";
                cout << "Expected: " << ans_line << endl;
                cout << "Found: " << out_line << endl;
                return 0;
            }

            else
            {
                cout << "Test " << t << " passed\n";
            }
            t++;
        }
    }
}