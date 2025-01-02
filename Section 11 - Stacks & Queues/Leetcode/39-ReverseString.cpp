#include <string>
#include <stack>
#include <iostream>

using namespace std;

using std::string; // Allows the use of 'string' instead of 'std::string'
using std::stack; // Allows the use of 'stack' instead of 'std::stack'

string reverseString(const string& str) {
    auto charStack = std::stack<char>();
    string reversedString;

    for(auto c : str) {
        charStack.push(c);
    }

    while (charStack.size()) {
        reversedString += charStack.top();
        charStack.pop();
    }

    return reversedString;
}


void test() {
    cout << "\n----- Test: Reverse Empty String -----\n";
    {
        string input = "";
        cout << "Input: \"" << input << "\"\n";
        cout << "Output: \"" << reverseString(input) << "\" - EXPECTED: \"\"\n";
        cout << (reverseString(input) == "" ? "PASS\n" : "FAIL\n");
    }

    cout << "\n----- Test: Reverse Single Character String -----\n";
    {
        string input = "A";
        cout << "Input: \"" << input << "\"\n";
        cout << "Output: \"" << reverseString(input) << "\" - EXPECTED: \"A\"\n";
        cout << (reverseString(input) == "A" ? "PASS\n" : "FAIL\n");
    }

    cout << "\n----- Test: Reverse Two Character String -----\n";
    {
        string input = "AB";
        cout << "Input: \"" << input << "\"\n";
        cout << "Output: \"" << reverseString(input) << "\" - EXPECTED: \"BA\"\n";
        cout << (reverseString(input) == "BA" ? "PASS\n" : "FAIL\n");
    }

    cout << "\n----- Test: Reverse Multiple Character String -----\n";
    {
        string input = "Hello, World!";
        cout << "Input: \"" << input << "\"\n";
        cout << "Output: \"" << reverseString(input) << "\" - EXPECTED: \"!dlroW ,olleH\"\n";
        cout << (reverseString(input) == "!dlroW ,olleH" ? "PASS\n" : "FAIL\n");
    }

    cout << "\n----- Test: Reverse String With Whitespace -----\n";
    {
        string input = "  A B C  ";
        cout << "Input: \"" << input << "\"\n";
        cout << "Output: \"" << reverseString(input) << "\" - EXPECTED: \"  C B A  \"\n";
        cout << (reverseString(input) == "  C B A  " ? "PASS\n" : "FAIL\n");
    }

    cout << "\n----- Test: Reverse String With Special Characters -----\n";
    {
        string input = "@#$%^&*()";
        cout << "Input: \"" << input << "\"\n";
        cout << "Output: \"" << reverseString(input) << "\" - EXPECTED: \")(*&^%$#@\"\n";
        cout << (reverseString(input) == ")(*&^%$#@" ? "PASS\n" : "FAIL\n");
    }
}

int main() {
    test();
}
