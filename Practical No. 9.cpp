// Implement C++ program for expression conversion as infix to 
// postfix and its evaluation using stack based on given conditions:
// a) Operands and operator, both must be single character.
// b) Input Postfix expression must be in a desired format.
// Only '+', '-', '*' and '/ ' operators are expected.

#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') 
        return 1; 
    if (op == '*' || op == '/') 
        return 2; 
    return 0; 
}

int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b; 
        case '-': return a - b; 
        case '*': return a * b; 
        case '/': return a / b; 
    }
    return 0; 
}

string infixToPostfix(const string& infix) {
    stack<char> operators; 
    string postfix; 

    for (char ch : infix) { 
        if (isalpha(ch) || isdigit(ch)) { 
            postfix += ch; 
        } else if (ch == '(') { 
            operators.push(ch); 
        } else if (ch == ')') { 
            while (!operators.empty() && operators.top() != '(') { 
                postfix += operators.top(); 
                operators.pop(); 
            } 
            if (!operators.empty()) 
                operators.pop(); 
        } else { 
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) { 
                postfix += operators.top(); 
                operators.pop(); 
            } 
            operators.push(ch); 
        } 
    } 

    while (!operators.empty()) { 
        postfix += operators.top(); 
        operators.pop(); 
    }

    return postfix; 
}

int evaluatePostfix(const string& postfix) {
    stack<int> operands;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            operands.push(ch - '0'); 
        } else {
            int b = operands.top(); operands.pop(); 
            int a = operands.top(); operands.pop(); 
            operands.push(applyOperation(a, b, ch)); 
        } 
    }

    return operands.top(); 
}

int main() {
    string infix; 

    cout << "Enter an infix expression: "; 
    cin >> infix; 

    string postfix = infixToPostfix(infix); 
    cout << "Postfix expression: " << postfix << endl; 

    int result = evaluatePostfix(postfix); 
    cout << "Result of evaluation: " << result << endl; 
}
