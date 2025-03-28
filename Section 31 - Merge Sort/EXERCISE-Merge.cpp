#include <iostream>

using namespace std;

void merge(int array[], int leftIndex, int midIndex, int rightIndex) {
	//   +=====================================================+
	//   |                 WRITE YOUR CODE HERE                |
	//   | Description:                                        |
	//   | - This function merges two sorted arrays into one.  |
	//   | - It is a part of the Merge Sort algorithm.         |
	//   | - Takes three index values to divide the array.     |
	//   |                                                     |
	//   | Return type: void                                   |
	//   |                                                     |
	//   | Tips:                                               |
	//   | - 'leftArray' and 'rightArray' are temp arrays.     |
	//   | - They store parts of the original array.           |
	//   | - 'i' and 'j' loop through these arrays.             |
	//   | - 'index' is for placing sorted elements back.      |
	//   | - Check output from Test.cpp in "User logs".        |
	//   +=====================================================+
    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;

    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

    for (int i = 0; i < leftArraySize; i++) {
        leftArray[i] = array[leftIndex + i];
    }
    for (int j = 0; j < rightArraySize; j++) {
        rightArray[j] = array[midIndex + 1 + j];
    }

    int index = leftIndex;
    int i = 0;
    int j = 0;

    while (i < leftArraySize && j < rightArraySize) {
        if (leftArray[i] < rightArray[j]) {
            array[index] = leftArray[i];
            index++;
            i++;
        } else {
            array[index] = rightArray[j];
            index++;
            j++;
        }
    }

    while (i < leftArraySize) {
        array[index] = leftArray[i];
        index++;
        i++;
    }

    while (j < rightArraySize) {
        array[index] = rightArray[j];
        index++;
        j++;
    }
}
 
 
int main() {
    
    int myArray[] = {1,3,7,8,2,4,5,6};

    int size = sizeof(myArray) / sizeof(myArray[0]);
    int leftIndex = 0;
    int rightIndex = size - 1;
    int midIndex = (size / 2) - 1;


    merge(myArray, leftIndex, midIndex, rightIndex);


    for (auto value : myArray) {  
        cout << value << " ";
    }
    
    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 7 8 
        
     */

}

