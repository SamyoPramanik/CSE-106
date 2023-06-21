#include <iostream>
#include <stack>
#include <cmath>
#include <string>

using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrecedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0;
}

double applyOperator(double a, double b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 0.0;
    }
}

double evaluateExpression(string expression)
{
    stack<double> valueStack;
    stack<char> operatorStack;

    for (int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];

        if (isdigit(c))
        {
            string numStr;
            numStr += c;

            while (i + 1 < expression.length() && (isdigit(expression[i + 1]) || expression[i + 1] == '.'))
            {
                numStr += expression[i + 1];
                i++;
            }

            double num = stod(numStr);
            valueStack.push(num);
        }
        else if (c == '(')
        {
            operatorStack.push(c);
        }
        else if (c == ')')
        {
            while (!operatorStack.empty() && operatorStack.top() != '(')
            {
                char op = operatorStack.top();
                operatorStack.pop();

                double operand2 = valueStack.top();
                valueStack.pop();
                double operand1 = valueStack.top();
                valueStack.pop();

                double result = applyOperator(operand1, operand2, op);
                valueStack.push(result);
            }

            if (!operatorStack.empty())
                operatorStack.pop();
        }
        else if (isOperator(c))
        {
            while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(c))
            {
                char op = operatorStack.top();
                operatorStack.pop();

                double operand2 = valueStack.top();
                valueStack.pop();
                double operand1 = valueStack.top();
                valueStack.pop();

                double result = applyOperator(operand1, operand2, op);
                valueStack.push(result);
            }

            operatorStack.push(c);
        }
    }

    while (!operatorStack.empty())
    {
        char op = operatorStack.top();
        operatorStack.pop();

        double operand2 = valueStack.top();
        valueStack.pop();
        double operand1 = valueStack.top();
        valueStack.pop();

        double result = applyOperator(operand1, operand2, op);
        valueStack.push(result);
    }

    return valueStack.top();
}

int main()
{
    string expression;

    cout << "Enter a mathematical expression: ";
    getline(cin, expression);

    try
    {
        double result = evaluateExpression(expression);
        cout << "Result: " << result << endl;
    }
    catch (...)
    {
        cout << "Error: Invalid expression" << endl;
    }

    return 0;
}
