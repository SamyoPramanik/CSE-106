#include <iostream>
#include <cstring>
#include <ctype.h>
#include <cmath>
#include <cstdlib>
#include "stack.h"
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

void initialize()
{
    int j = 0;
    char test1[1000];
    for (int i = 0; i < strlen(expression); i++)
    {
        if (expression[i] == ' ')
            continue;
        else
            test1[j++] = expression[i];
    }
    test1[j] = '\0';

    j = 0;
    for (int i = 0; i < strlen(test1); i++)
    {
        if (test1[i] == ')' && test1[i + 1] == '(')
        {
            test[j++] = ')';
            test[j++] = '*';
        }

        else if (test1[i] == '-')
        {
            test[j++] = '-';
            test[j++] = '1';
            test[j++] = '*';
        }

        else
            test[j++] = test1[i];
    }
    test[j] = '\0';
}

void calculate()
{
    char c = op.topvalue();
    double b = operand.topvalue();
    operand.pop();
    double a = 0;

    if (operand.length())
    {
        a = operand.topvalue();
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
    op.clear();
    operand.clear();

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

bool checkValidity()
{
    initialize();
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
            if (bracket.isEmpty())
                return false;
            else
                bracket.pop();
        }
    }

    if (!bracket.isEmpty())
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