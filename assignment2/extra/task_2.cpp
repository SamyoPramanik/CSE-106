#include <iostream>
#include <cstring>
#include <ctype.h>
#include <cmath>
#include <cstdlib>
#include <stack>
using namespace std;

char expression[1000];
char test[1000];

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

bool isOperator2(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

void calculate()
{
    char c = op.top();
    double b = operand.top();
    operand.pop();
    double a = 0;

    if (operand.size())
    {
        a = operand.top();
        operand.pop();
    }
    double result;

    if (c == '+')
        result = a + b;

    if (c == '-')
        result = a - b;

    if (c == '*')
        result = a * b;

    if (c == '/')
    {
        if (b == 0)
            result = -93049049320;
        else
            result = a / b;
    }
    op.pop();
    operand.push(result);
}

double evaluate(char *expression)
{
    while (op.size())
        op.pop();

    while (operand.size())
        operand.pop();

    for (int i = 0; i < strlen(test); i++)
    {
        char c = test[i];
        if (c == ' ')
            continue;
        if ((i == 0 && c == '-' && isdigit(test[i + 1])) || (c == '-' && isOperator(test[i - 1]) && isdigit(test[i + 1])) || isdigit(c) || c == '.')
        {
            char number[100];
            int j = 0;
            number[j++] = c;
            i++;

            while (isdigit(test[i]) || test[i] == '.')
                number[j++] = test[i++];
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
            while (op.top() != '(')
            {
                calculate();
            }
            op.pop();
        }

        else
        {
            while (!op.empty() && precedence(op.top()) >= precedence(c))
            {
                calculate();
            }

            op.push(c);
        }
    }

    while (!op.empty())
    {
        calculate();
    }
    return operand.top();
}

bool checkValidity()
{
    int j = 0;
    for (int i = 0; i < strlen(expression); i++)
    {
        if (expression[i] == ' ')
            continue;
        else
            test[j++] = expression[i];
    }
    test[j] = '\0';
    int l = strlen(test);

    if (test[0] == ')' || test[0] == '+' || test[0] == '*' || test[0] == '/')
        return false;
    if (isOperator(test[l - 1]))
        return false;

    stack<char> bracket;
    for (int i = 0; i < l; i++)
    {
        if (test[i] == '(')
            bracket.push('(');
        else if (test[i] == ')')
        {
            if (bracket.empty())
                return false;
            else
                bracket.pop();
        }
    }

    if (!bracket.empty())
        return false;

    for (int i = 1; i < l - 1; i++)
    {
        if (test[i] == '+' || test[i] == '*' || test[i] == '/')
        {
            if ((test[i - 1] == ')' || isdigit(test[i - 1])) && (test[i + 1] == '(' || isdigit(test[i + 1]) || test[i + 1] == '-'))
                continue;
            else
                return false;
        }

        else if (test[i] == '-')
        {
            if ((isOperator2(test[i - 1]) || isdigit(test[i - 1])) && (test[i + 1] == '(' || test[i + 1] == '-' || isdigit(test[i + 1])))
                continue;
            else
                return false;
        }
    }

    return true;
}

int main()
{
    while (true)
    {
        cin.getline(expression, 1000);
        if (!checkValidity())
        {
            cout << "invalid expression" << endl;
        }
        else
        {
            double ans = evaluate(expression);
            cout << ans << endl;
        }
    }
}