#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

vector<int> subarraySum(const vector<int>& nums, int target) {
	//   +=====================================================+
	//   |                 WRITE YOUR CODE HERE                |
	//   | Description:                                        |
	//   | - This function finds a subarray in 'nums' that     |
	//   |   sums up to the given 'target'.                    |
	//   | - It uses an unordered_map for quick look-up.       |
	//   | - It returns the indices of the start and end       |
	//   |   elements of the subarray.                         |
	//   |                                                     |
	//   | Return type: vector<int>                            |
	//   |                                                     |
	//   | Tips:                                               |
	//   | - 'sumIndex' stores cumulative sums and their       |
	//   |   indices.                                          |
	//   | - 'currentSum' keeps track of the sum up to index i.|
	//   | - Use 'find' method for quick look-up in map.       |
	//   | - Check output from Test.cpp in "User logs".        |
	//   +=====================================================+
    unordered_map<int, vector<int>> sumIndex;
	for(auto i = 0; i < nums.size(); i++) {
    	for(auto j = i; j < nums.size(); j++) {
    	    auto currentSum = 0;
    	    
    	    for(auto k = i; k <= j; k++) {
    	        currentSum += nums[k];
    	    }
    	    
    	    if (sumIndex[currentSum].empty()) {
    	        sumIndex[currentSum] = {i, j};
    	    }
    	}
	}
	
	return sumIndex[target];
}

void test() {
    {
        cout << "\n----- Test: Empty Input -----\n";
        vector<int> nums;
        int target = 10;
        vector<int> result = subarraySum(nums, target);
        cout << "EXPECTED: No solution\n";
        cout << "RETURNED: " << (result.empty() ? "No solution" : "Has solution") << "\n";
        cout << (result.empty() ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: No Subarray Sum -----\n";
        vector<int> nums{1, 2, 3, 4, 5};
        int target = 100;
        vector<int> result = subarraySum(nums, target);
        cout << "EXPECTED: No solution\n";
        cout << "RETURNED: " << (result.empty() ? "No solution" : "Has solution") << "\n";
        cout << (result.empty() ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Entire Array -----\n";
        vector<int> nums{3, 2, 5};
        int target = 10;
        vector<int> result = subarraySum(nums, target);
        vector<int> expected{0, 2};
        cout << "EXPECTED: Indices (0, 2)\n";
        cout << "RETURNED: Indices (" << (result.empty() ? "" : to_string(result[0])) << ", " 
             << (result.empty() ? "" : to_string(result[1])) << ")\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Partial Array -----\n";
        vector<int> nums{1, 2, 3, 4, 5};
        int target = 9;
        vector<int> result = subarraySum(nums, target);
        vector<int> expected{1, 3};
        cout << "EXPECTED: Indices (1, 3)\n";
        cout << "RETURNED: Indices (" << (result.empty() ? "" : to_string(result[0])) << ", " 
             << (result.empty() ? "" : to_string(result[1])) << ")\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Single Element -----\n";
        vector<int> nums{10};
        int target = 10;
        vector<int> result = subarraySum(nums, target);
        vector<int> expected{0, 0};
        cout << "EXPECTED: Indices (0, 0)\n";
        cout << "RETURNED: Indices (" << (result.empty() ? "" : to_string(result[0])) << ", " 
             << (result.empty() ? "" : to_string(result[1])) << ")\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: With Negative Numbers -----\n";
        vector<int> nums{1, -2, 3, 4, -5, 6};
        int target = 6;
        vector<int> result = subarraySum(nums, target);
        vector<int> expected{0, 3};
        cout << "EXPECTED: Indices (0, 3)\n";
        cout << "RETURNED: Indices (" << (result.empty() ? "" : to_string(result[0])) << ", " 
             << (result.empty() ? "" : to_string(result[1])) << ")\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }
    
}

int main() {
    test();
}

