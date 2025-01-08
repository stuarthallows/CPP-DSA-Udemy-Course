#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSumAlt1(const vector<int>& nums, int target) {
    unordered_map<int, vector<int>> numMap;
    for (auto i = 0; i < nums.size(); i++) {
        for (auto j = i + 1; j < nums.size(); j++) {
            auto sum = nums[i] + nums[j];
            numMap[sum] = {};
            numMap[sum].push_back(i);
            numMap[sum].push_back(j);
        }
    }

    return numMap[target];
}

vector<int> twoSum(const vector<int>& nums, int target) {
	//   +=====================================================+
	//   |                 WRITE YOUR CODE HERE                |
	//   | Description:                                        |
	//   | - This function finds two numbers in 'nums' that    |
	//   |   sum up to the given 'target'.                     |
	//   | - It uses an unordered_map for quick look-up.       |
	//   | - It returns the indices of the numbers that add    |
	//   |   up to the target.                                 |
	//   |                                                     |
	//   | Return type: vector<int>                            |
	//   |                                                     |
	//   | Tips:                                               |
	//   | - 'numMap' stores numbers and their indices.        |
	//   | - 'complement' is the value needed to reach target. |
	//   | - Use 'find' method for quick look-up in map.       |
	//   +=====================================================+    
    unordered_map<int, vector<int>> numMap;
    for (auto i = 0; i < nums.size(); i++) {
        for (auto j = i + 1; j < nums.size(); j++) {
            auto sum = nums[i] + nums[j];
            numMap[sum] = {};
            numMap[sum].push_back(i);
            numMap[sum].push_back(j);
        }
    }

    return numMap[target];
}

void test() {
    {
        cout << "\n----- Test: Empty Input -----\n";
        vector<int> nums;
        int target = 10;
        vector<int> result = twoSum(nums, target);
        cout << "EXPECTED: No two sum solution\n";
        cout << "RETURNED: " << (result.empty() ? "No solution" : "Has solution") << "\n";
        cout << (result.empty() ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Single Element -----\n";
        vector<int> nums{42};
        int target = 42;
        vector<int> result = twoSum(nums, target);
        cout << "EXPECTED: No two sum solution\n";
        cout << "RETURNED: " << (result.empty() ? "No solution" : "Has solution") << "\n";
        cout << (result.empty() ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Two Elements -----\n";
        vector<int> nums{3, 4};
        int target = 7;
        vector<int> result = twoSum(nums, target);
        vector<int> expected{0, 1};
        cout << "EXPECTED: Indices (0, 1)\n";
        cout << "RETURNED: Indices (" << (result.empty() ? "" : to_string(result[0])) << ", " 
             << (result.empty() ? "" : to_string(result[1])) << ")\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Multiple Elements -----\n";
        vector<int> nums{1, 3, 4, 2, 5};
        int target = 6;
        vector<int> result = twoSum(nums, target);
        vector<int> expected{2, 3};
        cout << "EXPECTED: Indices (2, 3)\n";
        cout << "RETURNED: Indices (" << (result.empty() ? "" : to_string(result[0])) << ", " 
             << (result.empty() ? "" : to_string(result[1])) << ")\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: No Match -----\n";
        vector<int> nums{10, 20, 30, 40};
        int target = 100;
        vector<int> result = twoSum(nums, target);
        cout << "EXPECTED: No two sum solution\n";
        cout << "RETURNED: " << (result.empty() ? "No solution" : "Has solution") << "\n";
        cout << (result.empty() ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: With Duplicates -----\n";
        vector<int> nums{3, 3, 4, 4};
        int target = 6;
        vector<int> result = twoSum(nums, target);
        vector<int> expected{0, 1};
        cout << "EXPECTED: Indices (0, 1)\n";
        cout << "RETURNED: Indices (" << (result.empty() ? "" : to_string(result[0])) << ", " 
             << (result.empty() ? "" : to_string(result[1])) << ")\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }
}

int main() {
    test();
}

