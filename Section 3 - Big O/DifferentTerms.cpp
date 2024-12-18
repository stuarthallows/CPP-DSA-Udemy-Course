#include <iostream>

using namespace std;

// O(a + b)

void addToEnd(int a, int b) {
    for (int i = 0; i < a; i++) {
        cout << i << endl;
    }

    for (int j = 0; j < b; j++) {
        cout << j << endl;
    }
}

int main() { 
    addToEnd(5, 10);
}
