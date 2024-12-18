#include <iostream>

using namespace std;

// 0(1)

int addItems(int n) {
    return n + n + n;
}

int main() { 
    cout << addItems(10) << endl;
}
