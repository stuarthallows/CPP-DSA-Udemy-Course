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
    
        //   +===================================================+
        //   |              WRITE YOUR CODE HERE                 |
        //   | Description:                                      |
        //   | - Inserts a new value into the min heap.          |
        //   | - Adjusts the heap to maintain the min heap       |
        //   |   property after the insertion.                   |
        //   |                                                   |
        //   | Parameters:                                       |
        //   | - value: The value to be inserted into the heap.  |
        //   |                                                   |
        //   | Behavior:                                         |
        //   | - The value is added to the end of the heap.      |
        //   | - The method then compares the added value with   |
        //   |   its parent, swapping them if the child is       |
        //   |   smaller, to maintain the min heap property.     |
        //   | - This comparison and potential swap continue     |
        //   |   until the new node is in its correct position   |
        //   |   or it becomes the root node.                    |
        //   +===================================================+
        void insert(int value) {
            heap.push_back(value);
            int current = heap.size() - 1;

            while(current > 0 && heap[current] < heap[parent(current)]) {
                swap(current, parent(current));
                current = parent(current);
            }
        }
};
    

static void test() {
    MinHeap heap;

    // Insert values into the heap
    vector<int> values = {35, 25, 15, 5, 20, 30, 10};
    cout << "Inserting values: ";
    for (int value : values) {
        cout << value << " ";
        heap.insert(value);
        
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

        cout << "\nHeap after insertion: ";
        heap.printHeap();
        cout << "Min Heap Property Valid? " << (isValidMinHeap ? "Yes" : "No") << "\n";
    }

    // Final Heap structure
    cout << "\nFinal Heap Structure: ";
    heap.printHeap();
}

int main() {
    test();
}