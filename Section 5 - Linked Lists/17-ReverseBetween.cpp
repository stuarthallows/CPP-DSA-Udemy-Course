#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
        int length;
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            length = 1;
        }
    
        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
    
        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }

        int getLength() {
            return length;
        }
        
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            length = 0;
        }
    
        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* currentNode = head;
                while (currentNode->next != nullptr) {
                    currentNode = currentNode->next;
                }
                currentNode->next = newNode;
            }
            length++;
        }
    
        void deleteFirst() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
            } else {
                head = head->next;
            }
            delete temp;
            length--;
        }

        /*
            Reverse the list by traversing the and reversing the direction of each pointer.
            Before, temp and after pointers will move through the list in unison.

            1. Swap the head and tail pointers.
            2. Initialise temp to head, and before and after to nullptr.
            3. For each item in the list
                1. Set after to temp->next
                2. Set temp->next to before
                3. Set before to temp (move up the before pointer)
                4. Set temp to after (move up the temp pointer)
         */
        void reverse() {
            Node* after = nullptr;
            Node* before = nullptr;

            auto temp = head;
            for(int i = 0; i < length; i++) {
                after = temp->next;
                temp->next = before;
                before = temp;
                temp = after;
            }
        }
    
        //   +======================================================+
        //   |                 WRITE YOUR CODE HERE                 |
        //   | Description:                                         |
        //   | - Reverse nodes between positions m and n            |
        //   | - Return type: void                                  |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Create a dummy node and set its next to head       |
        //   | - Use 'prev' pointer to go to m-th node              |
        //   | - Use 'current' pointer for m+1 to n nodes           |
        //   | - Loop to reverse m+1 to n nodes                     |
        //   | - Update original list's head                        |
        //   | - Free dummy node memory                             |
        //   +======================================================+
        void reverseBetween(int m, int n) {
            // Node* dummy = new Node(0);
            // dummy->next = head;

            auto prev = head;
            for(auto i = 0; i < m; i++) {
                prev = prev->next;
            }

            auto current = prev;

            // delete dummy;
        }
};


static void test() {
    // Helper function to check pass/fail
    auto checkTestResult = [](bool condition) {
        cout << (condition ? "PASS" : "FAIL") << endl;
    };


    // Test: ReverseBetweenMultipleElements
    {
        cout << "\n------ Test: ReverseBetweenMultipleElements ------\n";
        cout << "reverseBetween( 1, 4 )\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(4);
        list.append(5);
        list.append(6);
        
        cout << "BEFORE:    ";
        list.printList();
        
        list.reverseBetween(1, 4);
        
        cout << "AFTER:     ";
        list.printList();
        
        // Check condition
        Node* head = list.getHead();
        checkTestResult(
          head && 
          head->value == 1 &&
          head->next->value == 5 &&
          head->next->next->value == 4 &&
          head->next->next->next->value == 3 &&
          head->next->next->next->next->value == 2 && 
          head->next->next->next->next->next->value == 6
        );
    }
    
}

int main() {
    test();
}
