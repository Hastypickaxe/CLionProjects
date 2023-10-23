#include <iostream>
#include <string>
#include <stack>
#include <cctype>

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

int main() {
    char select;

    do {
        string infix, postfix;

        cout << "Enter an infix expression : ";
        cin >> infix;

        postfix = infixToPostfix(infix);

        cout << "Postfix expression : " << postfix << endl;
        cout << "More (y/n) ? ";
        cin >> select;
    } while (select == 'y' || select == 'Y');

    return 0;
}
