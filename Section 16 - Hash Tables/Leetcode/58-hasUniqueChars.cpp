#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool hasUniqueChars(const string& str) {
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function checks if a string 'str' has unique |
    //   |   characters.                                       |
    //   | - It uses an unordered_set for quick look-up.       |
    //   | - It returns a boolean value.                       |
    //   |                                                     |
    //   | Return type: bool                                   |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'charSet' stores characters we've seen.           |
    //   | - Loop through 'str' to populate 'charSet'.         |
    //   | - Use 'find' method for quick look-up in set.       |
    //   | - If a duplicate is found, return false.            |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    unordered_set<char> charSet(str.begin(), str.end());
    return charSet.size() == str.size();
}

// Helper to indicate test result
void displayResult(bool output, bool expected) {
    cout << "EXPECTED: " << (expected ? "True" : "False") << '\n';
    cout << "RETURNED: " << (output ? "True" : "False") << '\n';
    cout << (output == expected ? "PASS\n" : "FAIL\n");
}

void test() {
    {
        cout << "\n----- Test: Empty String -----\n";
        string input = "";
        bool output = hasUniqueChars(input);
        displayResult(output, true);
    }
    {
        cout << "\n----- Test: Unique Chars -----\n";
        string input = "abc";
        bool output = hasUniqueChars(input);
        displayResult(output, true);
    }
    {
        cout << "\n----- Test: Duplicate Chars -----\n";
        string input = "aabc";
        bool output = hasUniqueChars(input);
        displayResult(output, false);
    }
    {
        cout << "\n----- Test: Case Sensitivity -----\n";
        string input = "AbC";
        bool output = hasUniqueChars(input);
        displayResult(output, true);
    }
    {
        cout << "\n----- Test: Numbers & Special Chars -----\n";
        string input = "a1@";
        bool output = hasUniqueChars(input);
        displayResult(output, true);
    }
    {
        cout << "\n----- Test: All Same Chars -----\n";
        string input = "aaaa";
        bool output = hasUniqueChars(input);
        displayResult(output, false);
    }
    {
        cout << "\n----- Test: Whitespace -----\n";
        string input = "a a";
        bool output = hasUniqueChars(input);
        displayResult(output, false);
    }
    {
        cout << "\n----- Test: Mixed Case Duplicates -----\n";
        string input = "Aa";
        bool output = hasUniqueChars(input);
        displayResult(output, true);
    }
    {
        cout << "\n----- Test: Long String -----\n";
        string input(256, 'a');
        bool output = hasUniqueChars(input);
        displayResult(output, false);
    }
    {
        cout << "\n----- Test: Full ASCII -----\n";
        string input;
        for (int i = 0; i < 128; ++i) {
            input += static_cast<char>(i);
        }
        bool output = hasUniqueChars(input);
        displayResult(output, true);
    }
}

int main() {
    test();
}
