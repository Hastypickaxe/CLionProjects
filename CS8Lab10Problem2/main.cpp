#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <map>

using namespace std;

int functionOperators(char op)
{
    if(op == '+' || op == '-')
    {
        return 1;
    }
    if(op == '*' || op == '/')
    {
        return 2;
    }
    return 0;
}

string infixToPostfix(const string& expression)
{
    stack<char> operatorStack;
    string postFixExpression = "";

    for(char symbol : expression)
    {
        if(isalnum(symbol))
        {
            postFixExpression += symbol;
        } else if(symbol == '(') {
            operatorStack.push(symbol);
        } else if(symbol == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postFixExpression += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();
        } else {
            while (!operatorStack.empty() && functionOperators(symbol) <= functionOperators(operatorStack.top())) {
                postFixExpression += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(symbol);
        }
    }

    while(!operatorStack.empty()) {
        postFixExpression += operatorStack.top();
        operatorStack.pop();
    }

    return postFixExpression;
}

int calculate(const string& postfixExpression) {
    stack<int> operand;

    for(char symbol : postfixExpression) {
        if(isdigit((symbol))) {
            operand.push(symbol - '0');
        } else {
            int operand2 = operand.top();
            operand.pop();
            int operand1 = operand.top();
            operand.pop();

            int result;
            switch (symbol) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    result = 0;
                    break;
            }
            operand.push(result);
        }
    }

    return operand.top();
}

int main() {
    char select;

    do {
        string infix, postfix;

        cout << "Enter an infix expression : ";
        cin >> infix;

        postfix = infixToPostfix(infix);
        int result = calculate(postfix);

        cout << "Postfix expression : " << postfix << endl;
        cout << "The value of the expression : " << result << endl;

        cout << "More (y/n) ? ";
        cin >> select;
    } while (select == 'y' || select == 'Y');

    return 0;
}
