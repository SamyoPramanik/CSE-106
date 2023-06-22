#include <iostream>
#include <cstring>
#include <ctype.h>
#include <cmath>
#include <cstdlib>
#include "stack.h"
using namespace std;

char expression[1000];
stack<char> op;
stack<double> operand;

int precedence(char c)
{
    if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '(';
}

void calculate()
{
    char c = op.topvalue();
    double b = operand.topvalue();
    operand.pop();
    double a = operand.topvalue();
    operand.pop();
    double result;

    if (c == '+')
        result = a + b;

    if (c == '-')
        result = a - b;

    if (c == '*')
        result = a * b;

    if (c == '/')
        result = a / b;

    op.pop();
    operand.push(result);
}

double evaluate(char *expression)
{

    for (int i = 0; i < strlen(expression); i++)
    {
        char c = expression[i];
        if (c == ' ')
            continue;
        if ((i == 0 && c == '-') || (c == '-' && isOperator(expression[i - 1])) || isdigit(c) || c == '.')
        {
            char number[100];
            int j = 0;
            number[j++] = c;
            i++;

            while (isdigit(expression[i]) || expression[i] == '.')
                number[j++] = expression[i++];
            i--;
            number[j] = '\0';

            double num = atof(number);
            operand.push(num);
            // cout << num << endl;
        }

        else if (c == '(')
            op.push(c);

        else if (c == ')')
        {
            while (op.topvalue() != '(')
            {
                calculate();
            }
            op.pop();
        }

        else
        {
            while (!op.isEmpty() && precedence(op.topvalue()) >= precedence(c))
            {
                calculate();
            }

            op.push(c);
        }
    }

    while (!op.isEmpty())
    {
        calculate();
    }
    return operand.topvalue();
}

// bool checkValidity()
// {
//     char test[1000];
//     int j = 0;
//     for (int i = 0; i < strlen(expression); i++)
//     {
//         if (expression[i] == ' ')
//             continue;
//         else
//             test[j++] = expression[i];
//     }
//     test[j] = '\0';
// }

int main()
{
    cin.getline(expression, 1000);
    double ans = evaluate(expression);
    cout << ans << endl;
}