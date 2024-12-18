#include <iostream>

using namespace std;

// Another way to simplify the Big O notation is to remove the non-dominants.
// O(n^2 + n) = O(n^2), as n^2 is the dominant term.

void printItems(int n) {
    // O(n^2)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << j << endl;
        }
    }

    // O(n)
    for (int k = 0; k < n; k++) {
            cout << k << endl;
    }
}



int main() { 

    printItems(10);

}
