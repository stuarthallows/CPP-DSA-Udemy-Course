#include <iostream>
#include <utility>
#include <unordered_set>
#include <vector>

using namespace std;


vector<vector<int>> findPairs(const vector<int>& arr1, const vector<int>& arr2, int target) {
    //   +=========================================================+
    //   |                 WRITE YOUR CODE HERE                    |
    //   | Description:                                            |
    //   | - This function finds all pairs of integers from        |
    //   |   'arr1' and 'arr2' that sum up to 'target'.            |
    //   | - It uses an unordered_set for quick look-up.           |
    //   | - It returns a 2D vector containing the pairs.          |
    //   |                                                         |
    //   | Return type: vector<vector<int>>                        |
    //   |                                                         |
    //   | Tips:                                                   |
    //   | - 'mySet' stores numbers from 'arr1'.                   |
    //   | - 'pairs' will store the pairs that meet the target.    |
    //   | - Loop through 'arr1' to populate 'mySet'.              |
    //   | - Loop through 'arr2' to find pairs.                    |
    //   | - Use 'find' method for quick look-up in set.           |
    //   | - Check output from Test.cpp in "User logs".            |
    //   +=========================================================+
    unordered_set<int> mySet(arr1.begin(), arr1.end());
    vector<vector<int>> pairs;

    for (int num : arr2) {
        int complement = target - num;
        if (mySet.find(complement) != mySet.end()) {
            pairs.push_back({complement, num});
        }
    }

    return pairs;
}

// Helper function to display test result
void displayResult(vector<vector<int>> output, size_t expected,
                   vector<int> arr1, vector<int> arr2, int target) {
    cout << "arr1: ";
    for (int num : arr1) cout << num << " ";
    cout << '\n';
    cout << "arr2: ";
    for (int num : arr2) cout << num << " ";
    cout << '\n';
    cout << "Target: " << target << '\n';
    cout << "EXPECTED: Pairs found = " << expected << '\n';
    cout << "RETURNED: Pairs found = " << output.size() << '\n';
    cout << (output.size() == expected ? "PASS\n" : "FAIL\n");
}

void test() {
    {
        cout << "\n----- Test: Empty Vectors -----\n";
        vector<int> arr1 = {};
        vector<int> arr2 = {};
        int target = 10;
        vector<vector<int>> output = findPairs(arr1, arr2, target);
        displayResult(output, 0, arr1, arr2, target);
    }
    {
        cout << "\n----- Test: Empty arr1 -----\n";
        vector<int> arr1 = {};
        vector<int> arr2 = {1, 2, 3};
        int target = 10;
        vector<vector<int>> output = findPairs(arr1, arr2, target);
        displayResult(output, 0, arr1, arr2, target);
    }
    {
        cout << "\n----- Test: Empty arr2 -----\n";
        vector<int> arr1 = {1, 2, 3};
        vector<int> arr2 = {};
        int target = 10;
        vector<vector<int>> output = findPairs(arr1, arr2, target);
        displayResult(output, 0, arr1, arr2, target);
    }
    {
        cout << "\n----- Test: No Pairs Found -----\n";
        vector<int> arr1 = {1, 2, 3};
        vector<int> arr2 = {7, 8, 9};
        int target = 6;
        vector<vector<int>> output = findPairs(arr1, arr2, target);
        displayResult(output, 0, arr1, arr2, target);
    }
    {
        cout << "\n----- Test: One Pair Found -----\n";
        vector<int> arr1 = {1, 2, 3};
        vector<int> arr2 = {9, 10, 11};
        int target = 10;
        vector<vector<int>> output = findPairs(arr1, arr2, target);
        displayResult(output, 1, arr1, arr2, target);
    }
    {
        cout << "\n----- Test: Multiple Pairs Found -----\n";
        vector<int> arr1 = {3, 4, 5};
        vector<int> arr2 = {4, 5, 6, 7};
        int target = 10;
        vector<vector<int>> output = findPairs(arr1, arr2, target);
        displayResult(output, 3, arr1, arr2, target);
    }
    {
        cout << "\n----- Test: Duplicate Elements In arr1 -----\n";
        vector<int> arr1 = {1, 2, 2, 3};
        vector<int> arr2 = {7, 8, 9};
        int target = 10;
        vector<vector<int>> output = findPairs(arr1, arr2, target);
        displayResult(output, 3, arr1, arr2, target);
    }
    {
        cout << "\n----- Test: Duplicate Elements In arr2 -----\n";
        vector<int> arr1 = {1, 2, 3};
        vector<int> arr2 = {7, 7, 8, 9};
        int target = 10;
        vector<vector<int>> output = findPairs(arr1, arr2, target);
        displayResult(output, 4, arr1, arr2, target);
    }
    {
        cout << "\n----- Test: Zero As Target -----\n";
        vector<int> arr1 = {-1, 0, 1};
        vector<int> arr2 = {1, 0, -1};
        int target = 0;
        vector<vector<int>> output = findPairs(arr1, arr2, target);
        displayResult(output, 3, arr1, arr2, target);
    }
}

int main() {
    test();
}
