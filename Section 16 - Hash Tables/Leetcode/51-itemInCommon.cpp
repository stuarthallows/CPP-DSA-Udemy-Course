#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

	//   +=====================================================+
	//   |                 WRITE YOUR CODE HERE                |
	//   | Description:                                        |
	//   | - This function checks if two vectors have a        |
	//   |   common element.                                   |
	//   | - It uses an unordered_map to store elements from   |
	//   |   the first vector.                                 |
	//   | - Then it checks each element from the second       |
	//   |   vector against the map.                           |
	//   |                                                     |
	//   | Return type: bool                                   |
	//   |                                                     |
	//   | Tips:                                               |
	//   | - 'myMap' stores elements from 'vect1' as keys.     |
	//   | - Loop through 'vect2' and check against 'myMap'.   |
	//   | - Check output from Test.cpp in "User logs".        |
	//   +=====================================================+
bool itemInCommon(vector<int> vect1, vector<int> vect2) {
	auto myMap = unordered_map<int, bool>{}; 

    for (auto i : vect1) {
		myMap.insert({i, true});
    }

	for (auto i : vect2) {
		if (myMap[i]) {
			return true;
		}
	}

    return false;
}

void test() {
    {
        cout << "\n----- Test: Has Items In Common -----\n";
        vector<int> vect1 = {1, 2, 3, 4, 5};
        vector<int> vect2 = {5, 6, 7, 8, 9};
        cout << "EXPECTED: True\n";
        cout << "RETURNED: " << (itemInCommon(vect1, vect2) ? "True\n" : "False\n");
        cout << (itemInCommon(vect1, vect2) ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: No Items In Common -----\n";
        vector<int> vect1 = {1, 2, 3, 4, 5};
        vector<int> vect2 = {6, 7, 8, 9, 10};
        cout << "EXPECTED: False\n";
        cout << "RETURNED: " << (itemInCommon(vect1, vect2) ? "True\n" : "False\n");
        cout << (!itemInCommon(vect1, vect2) ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Both Vectors Empty -----\n";
        vector<int> vect1 = {};
        vector<int> vect2 = {};
        cout << "EXPECTED: False\n";
        cout << "RETURNED: " << (itemInCommon(vect1, vect2) ? "True\n" : "False\n");
        cout << (!itemInCommon(vect1, vect2) ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: One Vector Empty -----\n";
        vector<int> vect1 = {1, 2, 3, 4, 5};
        vector<int> vect2 = {};
        cout << "EXPECTED: False\n";
        cout << "RETURNED: " << (itemInCommon(vect1, vect2) ? "True\n" : "False\n");
        cout << (!itemInCommon(vect1, vect2) ? "PASS\n" : "FAIL\n");
    }
    
}

int main() {
	test();
}