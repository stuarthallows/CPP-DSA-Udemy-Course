#include <algorithm>
#include <iostream>
#include <ranges> 
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams(const vector<string>& strings) {
	//   +=====================================================+
	//   |                 WRITE YOUR CODE HERE                |
	//   | Description:                                        |
	//   | - This function groups anagrams from a given vector |
	//   |   of strings.                                       |
	//   | - It uses an unordered_map for organization.        |
	//   | - It sorts each string to form a canonical version. |
	//   | - Groups strings with the same canonical form.      |
	//   |                                                     |
	//   | Return type: vector<vector<string>>                 |
	//   |                                                     |
	//   | Tips:                                               |
	//   | - 'anagramGroups' maps canonical strings to groups. |
	//   | - 'canonical' is a sorted version of each string.   |
	//   | - 'result' holds the final groups of anagrams.      |
	//   | - Check output from Test.cpp in "User logs".        |
	//   +=====================================================+


    std::string s = "cppisawesome";

    // Sort the string in-place using std::ranges::sort
    std::ranges::sort(s);

    unordered_map<string, vector<string>> anagramGroups;
    for (const auto & word : strings) {      
        auto canonical = word;  
        sort(canonical.begin(), canonical.end());
        anagramGroups[canonical].push_back(word);
    }

    vector<vector<string>> result;
    for (const auto& [canonical, words] : anagramGroups) {
        result.push_back(words);
    }

    return result;
}

void printGroups(const vector<vector<string>>& groups) {
    cout << "{ ";
    for (const auto& group : groups) {
        cout << "( ";
        for (const string& str : group) {
            cout << str << " ";
        }
        cout << ") ";
    }
    cout << "}\n";
}

void test() {
    {
        cout << "\n----- Test: Empty Input -----\n";
        vector<string> input;
        vector<vector<string>> result = groupAnagrams(input);
        cout << "EXPECTED: No anagrams\n";
        cout << "RETURNED: ";
        printGroups(result);
        cout << (result.empty() ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Single Anagram Group -----\n";
        vector<string> input{"listen", "silent", "enlist"};
        vector<vector<string>> result = groupAnagrams(input);
        sort(result[0].begin(), result[0].end());
        sort(input.begin(), input.end());
        cout << "EXPECTED: ";
        printGroups({input});
        cout << "RETURNED: ";
        printGroups(result);
        cout << (result.size() == 1 && result[0] == input ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Multiple Anagram Groups -----\n";
        vector<string> input{"listen", "silent", "dog", "god", "evil", "vile"};
        vector<vector<string>> result = groupAnagrams(input);
        for (auto& group : result) {
            sort(group.begin(), group.end());
        }
        sort(result.begin(), result.end());
        vector<vector<string>> expected{
            {"dog", "god"},
            {"evil", "vile"},
            {"listen", "silent"}
        };
        sort(expected.begin(), expected.end());
        cout << "EXPECTED: ";
        printGroups(expected);
        cout << "RETURNED: ";
        printGroups(result);
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: No Anagrams -----\n";
        vector<string> input{"cat", "bat", "rat"};
        vector<vector<string>> result = groupAnagrams(input);
        vector<vector<string>> expected;
        for (const string& str : input) {
            expected.push_back({str});
        }
        sort(result.begin(), result.end());
        sort(expected.begin(), expected.end());
        cout << "EXPECTED: ";
        printGroups(expected);
        cout << "RETURNED: ";
        printGroups(result);
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }
}

int main() {
    test();
}
