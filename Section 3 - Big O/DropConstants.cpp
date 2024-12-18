#include <iostream>

using namespace std;

// The time complexity is O(2n) but as a rule of simplification we drop the constant so the time complexity is O(n)

void printItems(int n) {
    for (int i = 0; i < n; i++) {
        cout << i << endl;
    }

    for (int j = 0; j < n; j++) {
        cout << j << endl;
    }
}

int main() { 
    printItems(10);
}
