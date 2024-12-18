#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// adding or removing an item off the end of a vector is O(1)
// - use v.push_back() or v.pop_back()
void modifyEnd(int a) {
    vector<int> items = {1, 2, 3, 4, 5};
    items.push_back(a);
    items.pop_back();
}

// inserting or removing an item at the beginning or middle of a vector is O(n) as items to 
// the right of the insertion point need to be shifted, involving shifting items in the array
// and updating the indexes
void insertItem(int a, int b) {
    vector<int> items = {1, 2, 3, 4, 5};
    items.insert(items.begin() + 2, 100);
    items.erase(items.begin() + 1);
}

// finding an item in a vector by value is O(n) as it requires iterating through the vector
// finding by index is O(1) as it is a direct access
void findByValue(int value)
{
    vector<int> items = {1, 2, 3, 4, 5};
    auto it = find(items.begin(), items.end(), value);
    if (it != items.end())
    {
        cout << "Found: " << *it << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
}

int main() { 
    findByValue(3);
}
