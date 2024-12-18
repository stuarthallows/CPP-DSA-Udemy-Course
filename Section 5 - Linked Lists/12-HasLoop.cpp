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
        Node* tail;
        int length;
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
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

        Node* getTail() {
            return tail; 
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
            tail = nullptr;
            length = 0;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

        //   +======================================================+
        //   |                 WRITE YOUR CODE HERE                 |
        //   | Description:                                         |
        //   | - Check if the linked list has a loop                |
        //   | - Return type: bool                                  |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Use two pointers: 'slow' and 'fast'                |
        //   | - 'slow' moves one step, 'fast' moves two            |
        //   | - If they meet, a loop exists                        |
        //   | - Return true if loop found, false otherwise         |
        //   | - 'fast' checks for null and its 'next' for null     |
        //   +======================================================+
        // Uses Floyd's cycle-finding algorithm (also known as the "tortoise and the hare" algorithm) to detect the loop
        bool hasLoop() {
            auto slow = head;
            auto fast = head;

            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast) {
                    return true;
                }
            }

            return false;
        }
};




static void test() {
    // Function to convert boolean to string for easy comparison
    auto boolToStr = [](bool val) -> string {
        return val ? "True" : "False";
    };

    // Helper function to check test result
    auto checkTestResult = [](bool condition) {
        cout << (condition ? "PASS" : "FAIL") << endl;
    };

    // Test: EmptyListHasLoop
    {
        cout << "\n------ LinkedList Test: EmptyListHasLoop ------\n";
        
        LinkedList list(1);
        list.makeEmpty();
        
        list.printList();
        
        bool hasLoop = list.hasLoop();
        
        cout << "Has loop: " << boolToStr(hasLoop) << endl;
        
        checkTestResult(!hasLoop);
    }

    // Test: SingleElementNoLoop
    {
        cout << "\n------ LinkedList Test: SingleElementNoLoop ------\n";
        
        LinkedList list(1);
        
        list.printList();
        
        bool hasLoop = list.hasLoop();
        
        cout << "Has loop: " << boolToStr(hasLoop) << endl;
        
        checkTestResult(!hasLoop);
    }

    // Test: MultipleElementsNoLoop
    {
        cout << "\n------ LinkedList Test: MultipleElementsNoLoop ------\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(4);
        
        list.printList();
        
        bool hasLoop = list.hasLoop();
        
        cout << "Has loop: " << boolToStr(hasLoop) << endl;
        
        checkTestResult(!hasLoop);
    }

    // Test: SingleElementWithLoop
    {
        cout << "\n------ LinkedList Test: SingleElementWithLoop ------\n";
        
        LinkedList list(1);
        Node* tail = list.getTail();
        tail->next = list.getHead();
        
        // Can't print the list because it has a loop!
        
        bool hasLoop = list.hasLoop();
        
        cout << "Has loop: " << boolToStr(hasLoop) << endl;
        
        tail->next = nullptr;  // Break the loop
        
        checkTestResult(hasLoop);
    }

    // Test: MultipleElementsWithLoop
    {
        cout << "\n------ LinkedList Test: MultipleElementsWithLoop ------\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(4);
        Node* tail = list.getTail();
        tail->next = list.getHead();
        
        // Can't print the list because it has a loop!
        
        bool hasLoop = list.hasLoop();
        
        cout << "Has loop: " << boolToStr(hasLoop) << endl;
        
        tail->next = nullptr;  // Break the loop
        
        checkTestResult(hasLoop);
    }
    
}

int main() {
    test();
}