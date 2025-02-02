#include <iostream>
#include <vector>
#include <climits> 

using namespace std;

class Heap {
    private:
        vector<int> heap;

        int leftChild(int index) {
            return 2 * index + 1;
        }

        int rightChild(int index) {
            return 2 * index + 2;
        }

        int parent(int index) {
            return (index - 1) / 2;
        }

        void swap(int index1, int index2) {
            int temp = heap[index1];
            heap[index1] = heap[index2];
            heap[index2] = temp;
        }

        void sinkDown(int index) {
            int maxIndex = index;
            while (true) {
                int leftIndex = leftChild(index);
                int rightIndex = rightChild(index);

                if (leftIndex < heap.size() && heap[leftIndex] > heap[maxIndex]) {
                    maxIndex = leftIndex;
                }

                if (rightIndex < heap.size() && heap[rightIndex] > heap[maxIndex]) {
                    maxIndex = rightIndex;
                }

                if (maxIndex != index) {
                    swap(index, maxIndex);
                    index = maxIndex;
                } else {
                    return;
                }
            }
        }
    public:
        void printHeap() {
            cout << "\n[";
            for (size_t i = 0; i < heap.size(); i++) {
                cout << heap[i];
                if (i < heap.size() - 1) { 
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        }
        
        const vector<int>& getHeap() const {
            return heap;
        }

        void insert(int value) {
            heap.push_back(value);
            int current = heap.size() - 1;

            while (current > 0 && heap[current] > heap[parent(current)]) {
                swap(current, parent(current));
                current = parent(current);
            }
        }

        //   +===================================================+
        //   |              WRITE YOUR CODE HERE                 |
        //   | Description:                                      |
        //   | - Removes and returns the maximum value from      |
        //   |   the heap.                                       |
        //   | - Maintains the heap's property by reorganizing   |
        //   |   the heap after the removal.                     |
        //   |                                                   |
        //   | Return:                                           |
        //   | - The maximum value in the heap. If the heap is   |
        //   |   empty, returns INT_MIN as an error indication.  |
        //   |                                                   |
        //   | Behavior:                                         |
        //   | - If the heap is empty, returns INT_MIN.          |
        //   | - Saves the maximum value (the root of the heap). |
        //   | - Replaces the root with the last element in the  |
        //   |   heap and then restores the heap property using  |
        //   |   a sink down operation.                          |
        //   | - If there's only one element, it is simply       |
        //   |   removed from the heap.                          |
        //   +===================================================+
        int remove() {
            if (heap.empty()) {
                return INT_MIN;
            }

            int maxValue = heap.front();

            if (heap.size() == 1) {
                heap.pop_back();
            } else {
                heap[0] = heap.back();
                heap.pop_back();
                sinkDown(0);
            }

            return maxValue;
        }
};


static void test() {
    Heap heap;

    // Insert values into the heap
    vector<int> valuesToInsert = {10, 20, 30, 5, 15, 25, 35};
    cout << "Inserting values: ";
    for (int value : valuesToInsert) {
        cout << value << " ";
        heap.insert(value);
    }
    cout << "\nInitial Heap: ";
    heap.printHeap();

    // Remove values from the heap and test after each removal
    while (!heap.getHeap().empty()) {
        int removedValue = heap.remove();
        cout << "\nRemoved Value: " << removedValue;
        cout << "\nHeap after removal: ";
        heap.printHeap();

        // Verify max heap property
        const vector<int>& currentHeap = heap.getHeap();
        bool isValidMaxHeap = true;
        for (size_t i = 0; i < currentHeap.size(); i++) {
            int left = 2 * i + 1;  // Calculating left child index
            int right = 2 * i + 2; // Calculating right child index
            if (left < currentHeap.size() && currentHeap[i] < currentHeap[left]) {
                isValidMaxHeap = false;
                break;
            }
            if (right < currentHeap.size() && currentHeap[i] < currentHeap[right]) {
                isValidMaxHeap = false;
                break;
            }
        }

        cout << "\nMax Heap Property Valid? " << (isValidMaxHeap ? "Yes" : "No") << "\n";
    }

    // Check if heap is empty at the end
    cout << "\nFinal Heap (Should be empty): ";
    heap.printHeap();
}

int main() {
    test();
}