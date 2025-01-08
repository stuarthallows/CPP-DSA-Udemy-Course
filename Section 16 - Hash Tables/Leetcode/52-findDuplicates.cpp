#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> findDuplicates(const vector<int>& nums) {
	//   +=====================================================+
	//   |                 WRITE YOUR CODE HERE                |
	//   | Description:                                        |
	//   | - This function finds duplicate integers in a given |
	//   |   vector.                                           |
	//   | - It uses an unordered_map to count each integer's  |
	//   |   occurrences.                                      |
	//   | - Loops through the map to find duplicates.         |
	//   |                                                     |
	//   | Return type: vector<int>                            |
	//   |                                                     |
	//   | Tips:                                               |
	//   | - 'numCounts' keeps track of each integer's count.  |
	//   | - 'duplicates' stores duplicate integers found.     |
	//   | - Check output from Test.cpp in "User logs".        |
	//   +=====================================================+
	unordered_map<int, int> numCounts;
	vector<int> duplicates;
	
	for (auto i : nums) {
	    auto count = ++numCounts[i];
	    if (count > 1 && find(duplicates.begin(), duplicates.end(), i) == duplicates.end()) {
	        duplicates.push_back(i);
	    }
	}
	
	return duplicates;
}

void test() {
    auto printVector = [](const vector<int>& v) {
        cout << "(";
        for(int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i < v.size() - 1) cout << ", ";
        }
        cout << ")";
    };

    {
        cout << "\n----- Test: No Duplicates -----\n";
        vector<int> nums = {1, 2, 3, 4, 5};
        vector<int> expected = {};
        vector<int> result = findDuplicates(nums);
        cout << "EXPECTED: No Duplicates\n";
        cout << "RETURNED: ";
        printVector(result);
        cout << "\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Some Duplicates -----\n";
        vector<int> nums = {1, 2, 3, 2, 1, 4, 5, 6, 5};
        vector<int> expected = {1, 2, 5};
        vector<int> result = findDuplicates(nums);
        sort(result.begin(), result.end());
        cout << "EXPECTED: Has Duplicates: ";
        printVector(expected);
        cout << "\n";
        cout << "RETURNED: ";
        printVector(result);
        cout << "\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: All Duplicates -----\n";
        vector<int> nums = {1, 1, 2, 2, 3, 3};
        vector<int> expected = {1, 2, 3};
        vector<int> result = findDuplicates(nums);
        sort(result.begin(), result.end());
        cout << "EXPECTED: Has Duplicates: (1, 2, 3)\n";
        cout << "RETURNED: ";
        printVector(result);
        cout << "\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Empty Vector -----\n";
        vector<int> nums = {};
        vector<int> expected = {};
        vector<int> result = findDuplicates(nums);
        cout << "EXPECTED: No Duplicates\n";
        cout << "RETURNED: ";
        printVector(result);
        cout << "\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }
}

int main() {
	test();
}
