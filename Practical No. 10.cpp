// In any language program mostly syntax error occurs due to 
// unbalancing delimiter such as (),{},[]. Write C++ program using 
// stack to check whether given expression is well
// Parenthesized or not.

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

class Stack {
    int top;
    char arr[MAX];

public:
    Stack() {
        top = -1;
    }

    void push(char c) {
        if (top == MAX - 1) {
            cout << "Stack overflow!" << endl;
        } else {
            arr[++top] = c;
        }
    }

    char pop() {
        if (top == -1) {
            cout << "Stack underflow!" << endl;
            return -1;
        } else {
            return arr[top--];
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool isWellParenthesized(string expr) {
    Stack s;
    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (s.isEmpty()) {
                return false;
            }
            char top = s.pop();
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.isEmpty();
}

int main() {
    string expression;
    cout << "Enter an expression with delimiters: ";
    getline(cin, expression);

    if (isWellParenthesized(expression)) {
        cout << "The expression is well-parenthesized." << endl;
    } else {
        cout << "The expression is NOT well-parenthesized." << endl;
    }
    return 0;
}
