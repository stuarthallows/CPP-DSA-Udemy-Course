#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool isBalancedParentheses(const string& parentheses) {
    stack<char> charStack;

    for (char c : parentheses) {
        if (c == '(') {
            charStack.push(c);
        } else if (c == ')') {
            if (charStack.empty()) {
                return false;
            }
            charStack.pop();
        }
    }

    return charStack.empty();
}

void test() {
    cout << "\n----- Test: Empty Parentheses -----\n";
    {
        string input = "";
        cout << "Input: \"" << input << "\"\n";
        cout << "Output: " << (isBalancedParentheses(input) ? "Balanced" : "Unbalanced") << " - EXPECTED: Balanced\n";
        cout << (isBalancedParentheses(input) ? "PASS\n" : "FAIL\n");
    }

    cout << "\n----- Test: Balanced Parentheses -----\n";
    {
        string inputs[] = {"()", "(())", "(()(()))"};
        for (const string &input : inputs) {
            cout << "Input: \"" << input << "\"\n";
            cout << "Output: " << (isBalancedParentheses(input) ? "Balanced" : "Unbalanced") << " - EXPECTED: Balanced\n";
            cout << (isBalancedParentheses(input) ? "PASS\n" : "FAIL\n");
        }
    }

    cout << "\n----- Test: Unbalanced Opening Parentheses -----\n";
    {
        string inputs[] = {"(", "(()", "((())"};
        for (const string &input : inputs) {
            cout << "Input: \"" << input << "\"\n";
            cout << "Output: " << (isBalancedParentheses(input) ? "Balanced" : "Unbalanced") << " - EXPECTED: Unbalanced\n";
            cout << (!isBalancedParentheses(input) ? "PASS\n" : "FAIL\n");
        }
    }

    cout << "\n----- Test: Unbalanced Closing Parentheses -----\n";
    {
        string inputs[] = {")", "())", "(()))"};
        for (const string &input : inputs) {
            cout << "Input: \"" << input << "\"\n";
            cout << "Output: " << (isBalancedParentheses(input) ? "Balanced" : "Unbalanced") << " - EXPECTED: Unbalanced\n";
            cout << (!isBalancedParentheses(input) ? "PASS\n" : "FAIL\n");
        }
    }

    cout << "\n----- Test: Mixed Parentheses -----\n";
    {
        string balancedInput = "()()";
        string unbalancedInputs[] = {"()(", "())()"};

        cout << "Input: \"" << balancedInput << "\"\n";
        cout << "Output: " << (isBalancedParentheses(balancedInput) ? "Balanced" : "Unbalanced") << " - EXPECTED: Balanced\n";
        cout << (isBalancedParentheses(balancedInput) ? "PASS\n" : "FAIL\n");

        for (const string &input : unbalancedInputs) {
            cout << "Input: \"" << input << "\"\n";
            cout << "Output: " << (isBalancedParentheses(input) ? "Balanced" : "Unbalanced") << " - EXPECTED: Unbalanced\n";
            cout << (!isBalancedParentheses(input) ? "PASS\n" : "FAIL\n");
        }
    }
}

int main() {
    test();
}
