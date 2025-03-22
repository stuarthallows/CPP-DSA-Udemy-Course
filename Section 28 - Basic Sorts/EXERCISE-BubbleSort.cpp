#include <iostream>

using namespace std;


void bubbleSort(int values[], int size) {
    for(int i = size - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if (values[j] > values[j+1]) {
                int temp = values[j+1];
                values[j+1] = values[j];
                values[j] = temp;
            }
        }
    }
}


int main() {
    
    int myArray[] = {6,4,2,5,1,3};

    int size = sizeof(myArray) / sizeof(myArray[0]);


    bubbleSort(myArray, size);


    for (auto value : myArray) {  
        cout << value << " ";
    }

    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 
        
     */
    
}

