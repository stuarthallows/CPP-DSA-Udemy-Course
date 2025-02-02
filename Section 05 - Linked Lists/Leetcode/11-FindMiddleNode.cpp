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
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
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
        
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            tail = nullptr;
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
        }

        Node* findMiddleNode() {
            // Initialize slow and fast pointers to head
            Node* slow = head;
            Node* fast = head;
        
            // Traverse the list until fast reaches the end
            while (fast != nullptr && fast->next != nullptr) {
                // Move slow pointer one step forward
                slow = slow->next;
                
                // Move fast pointer two steps forward
                fast = fast->next->next;
            }
            
            // When the loop ends, slow points to the middle
            return slow;
        }
};


static void test() {
    // Function to convert nullptr to "0 (nullptr)"
    auto ptrToNum = [](Node* ptr) -> string {
        return (ptr == nullptr) ? "0 (nullptr)" : to_string(ptr->value);
    };

    // Helper function to check test result
    auto checkTestResult = [](bool condition) {
        cout << (condition ? "PASS" : "FAIL") << endl;
    };

    // Test: EmptyList
    {
        cout << "\n------ LinkedList Test: EmptyList ------\n";

        LinkedList list(1);
        list.makeEmpty();
        
        list.printList();
        
        Node* middle = list.findMiddleNode();
        
        cout << "Middle node: " << ptrToNum(middle) << endl;
        
        checkTestResult(middle == nullptr);
    }

    // Test: SingleElement
    {
        cout << "\n------ LinkedList Test: SingleElement ------\n";
        
        LinkedList list(1);
        
        list.printList();
        
        Node* middle = list.findMiddleNode();
        
        cout << "Middle node: " << ptrToNum(middle) << endl;

        checkTestResult(middle == list.getHead());
    }

    // Test: EvenNumberOfElements
    {
        cout << "\n------ LinkedList Test: EvenNumberOfElements ------\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(4);
        
        list.printList();
        
        Node* middle = list.findMiddleNode();
        
        cout << "Middle node: " << ptrToNum(middle) << endl;

        checkTestResult(middle->value == 3);
    }

    // Test: OddNumberOfElements
    {
        cout << "\n------ LinkedList Test: OddNumberOfElements ------\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        
        list.printList();
        
        Node* middle = list.findMiddleNode();
        
        cout << "Middle node: " << ptrToNum(middle) << endl;
        
        checkTestResult(middle->value == 2);
    }
}


int main() {
        
    test();
}



