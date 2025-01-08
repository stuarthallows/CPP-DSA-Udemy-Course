#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

char firstNonRepeatingChar(const string& input_string) {
	//   +======================================================+
	//   |                 WRITE YOUR CODE HERE                 |
	//   | Description:                                         |
	//   | - This function finds the first non-repeating char   |
	//   |   in a given string.                                 |
	//   | - It uses an unordered_map to count char occurrences |
	//   | - Loops through the string to check counts.          |
	//   |                                                      |
	//   | Return type: char                                    |
	//   |                                                      |
	//   | Tips:                                                |
	//   | - 'charCounts' keeps track of each char's count.     |
	//   | - Loops twice: once to count, once to find answer.   |
	//   | - Returns '\0' if no non-repeating char is found.    |
	//   +======================================================+
    unordered_map<char, int> charCounts;

    for (auto c : input_string) {
        ++charCounts[c];
    }

    for (char c : input_string) {
        if (charCounts[c] == 1) {
            return c;
        }
    }

    return '\0';
}

void test() {
    {
        cout << "\n----- Test: Empty String -----\n";
        string input;
        char result = firstNonRepeatingChar(input);
        cout << "EXPECTED: No non-repeating characters\n";
        cout << "RETURNED: " << (result == '\0' ? "No non-repeating characters" : "Character found") << "\n";
        cout << (result == '\0' ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Single Character -----\n";
        string input = "a";
        char result = firstNonRepeatingChar(input);
        cout << "EXPECTED: 'a'\n";
        cout << "RETURNED: '" << result << "'\n";
        cout << (result == 'a' ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: All Characters Repeat -----\n";
        string input = "aabbcc";
        char result = firstNonRepeatingChar(input);
        cout << "EXPECTED: No non-repeating characters\n";
        cout << "RETURNED: " << (result == '\0' ? "No non-repeating characters" : "Character found") << "\n";
        cout << (result == '\0' ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Some Characters Repeat -----\n";
        string input = "aabccde";
        char result = firstNonRepeatingChar(input);
        cout << "EXPECTED: 'b'\n";
        cout << "RETURNED: '" << result << "'\n";
        cout << (result == 'b' ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: No Characters Repeat -----\n";
        string input = "abcde";
        char result = firstNonRepeatingChar(input);
        cout << "EXPECTED: 'a'\n";
        cout << "RETURNED: '" << result << "'\n";
        cout << (result == 'a' ? "PASS\n" : "FAIL\n");
    }
}

int main() {
    test();
}
