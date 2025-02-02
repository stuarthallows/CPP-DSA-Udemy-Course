#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class MinHeap {
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
    
            while (current > 0 && heap[current] < heap[parent(current)]) {
                swap(current, parent(current));
                current = parent(current);
            }
        }
    
        void sinkDown(int index) {
            int minIndex = index;
            while (true) {
                int leftIndex = leftChild(index);
                int rightIndex = rightChild(index);
    
                if (leftIndex < heap.size() && heap[leftIndex] < heap[minIndex]) {
                    minIndex = leftIndex;
                }
    
                if (rightIndex < heap.size() && heap[rightIndex] < heap[minIndex]) {
                    minIndex = rightIndex;
                }
    
                if (minIndex != index) {
                    swap(index, minIndex);
                    index = minIndex;
                } else {
                    return;
                }
            }
        }
    
        //   +===================================================+
        //   |              WRITE YOUR CODE HERE                 |
        //   | Description:                                      |
        //   | - Removes and returns the minimum value from the  |
        //   |   min heap.                                       |
        //   | - Ensures the heap maintains its properties after |
        //   |   the removal of the root element.                |
        //   |                                                   |
        //   | Return:                                           |
        //   | - The minimum value in the heap. If the heap is   |
        //   |   empty, returns INT_MIN as a signal of underflow.|
        //   |                                                   |
        //   | Behavior:                                         |
        //   | - If the heap is empty, returns INT_MIN.          |
        //   | - Saves the minimum value (the root of the heap). |
        //   | - Replaces the root with the last element in the  |
        //   |   heap and restores the heap property using a     |
        //   |   sink down operation.                            |
        //   | - If there's only one element, it is simply       |
        //   |   removed from the heap.                          |
        //   +===================================================+
        int remove() {
            if (heap.empty()) {
                return INT_MIN;
            }

            int minValue = heap.front();

            if (heap.size() == 1) {
                heap.pop_back();
            } else {
                heap[0] = heap.back();
                heap.pop_back();
                sinkDown(0);
            }

            return minValue;
        }
};

static void test() {
    MinHeap heap;

    // Insert values into the heap
    vector<int> valuesToInsert = {35, 25, 15, 5, 20, 30, 10};
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

        // Verify min heap property
        const vector<int>& currentHeap = heap.getHeap();
        bool isValidMinHeap = true;
        for (size_t i = 0; i < currentHeap.size(); i++) {
            int left = 2 * i + 1;  // Calculating left child index
            int right = 2 * i + 2; // Calculating right child index
            if (left < currentHeap.size() && currentHeap[i] > currentHeap[left]) {
                isValidMinHeap = false;
                break;
            }
            if (right < currentHeap.size() && currentHeap[i] > currentHeap[right]) {
                isValidMinHeap = false;
                break;
            }
        }

        cout << "\nMin Heap Property Valid? " << (isValidMinHeap ? "Yes" : "No") << "\n";
    }

    // Check if heap is empty at the end
    cout << "\nFinal Heap (Should be empty): ";
    heap.printHeap();
}

int main() {
    test();
}