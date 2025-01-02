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
            if (head == nullptr) {
                return;
            }
    
            Node* dummy = new Node(0);
            dummy->next = head;
            Node* prev = dummy;
    
            for (int i = 0; i < m; i++) {
                prev = prev->next;
            }
    
            Node* current = prev->next;
            for (int i = 0; i < n - m; i++) {
                Node* temp = current->next;
                current->next = temp->next;
                temp->next = prev->next;
                prev->next = temp;
            }
    
            head = dummy->next;
            delete dummy;
        }
};


static void test() {
    // Helper function to check pass/fail
    auto checkTestResult = [](bool condition) {
        cout << (condition ? "PASS" : "FAIL") << endl;
    };

    // Test: ReverseBetweenEmptyList
    {
        cout << "\n------ Test: ReverseBetweenEmptyList ------\n";
        cout << "reverseBetween( 0, 2 )\n";
        
        LinkedList list(1);
        list.makeEmpty();
        
        cout << "BEFORE:    ";
        list.printList();
        
        list.reverseBetween(0, 2);
        
        cout << "AFTER:     ";
        list.printList();
        
        checkTestResult(list.getLength() == 0);
    }

    // Test: ReverseBetweenSingleElement
    {
        cout << "\n------ Test: ReverseBetweenSingleElement ------\n";
        cout << "reverseBetween( 0, 0 )\n";
        
        LinkedList list(1);
        
        cout << "BEFORE:    ";
        list.printList();
        
        list.reverseBetween(0, 0);
        
        cout << "AFTER:     ";
        list.printList();
        
        Node* head = list.getHead();
        checkTestResult(head && head->value == 1);
    }

    // Test: ReverseBetweenBothArgumentsSameNumber
    {
        cout << "\n------ Test: ReverseBetweenBothArgumentsSameNumber ------\n";
        cout << "reverseBetween( 1, 1 )\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        
        cout << "BEFORE:    ";
        list.printList();
        
        list.reverseBetween(1, 1);
        
        cout << "AFTER:     ";
        list.printList();
        
        Node* head = list.getHead();
        checkTestResult(
          head && 
          head->value == 1 && 
          head->next->value == 2 && 
          head->next->next->value == 3
        );
    }

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

    // Test: ReverseBetweenStartAtZero
    {
        cout << "\n------ Test: ReverseBetweenStartAtZero ------\n";
        cout << "reverseBetween( 0, 2 )\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(4);
        
        cout << "BEFORE:    ";
        list.printList();
        
        list.reverseBetween(0, 2);
        
        cout << "AFTER:     ";
        list.printList();
        
        // Check condition
        Node* head = list.getHead();
        checkTestResult(
          head && 
          head->value == 3 &&
          head->next->value == 2 &&
          head->next->next->value == 1 &&
          head->next->next->next->value == 4
        );
    }

    // Test: ReverseBetweenEndAtLast
    {
        cout << "\n------ Test: ReverseBetweenMiddleToLast ------\n";
        cout << "reverseBetween( 1, 2 )\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        
        cout << "BEFORE:    ";
        list.printList();
        
        list.reverseBetween(1, 2);
        
        cout << "AFTER:     ";
        list.printList();
        
        // Check condition
        Node* head = list.getHead();
        checkTestResult(
          head && 
          head->value == 1 &&
          head->next->value == 3 &&
          head->next->next->value == 2
        );
    }
    
}

int main() {
    test();
}
