#include <iostream>
#include <unordered_set>

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

        //   +======================================================+
        //   |                 WRITE YOUR CODE HERE                 |
        //   | Description:                                         |
        //   | - Remove duplicate nodes from the list               |
        //   | - Return type: void                                  |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Use two pointers: 'current' and 'runner'           |
        //   | - 'current' scans each node                          |
        //   | - 'runner' checks for duplicates ahead               |
        //   | - If duplicate found, delete it                      |
        //   | - Update 'next' pointers and reduce length           |
        //   | - No return value, list updated in-place             |
        //   +======================================================+
        void removeDuplicates() {
            if (length < 2) {
                return;
            }

            auto current = head;
            while(current != nullptr) {
                auto runner = current;
                while (runner->next != nullptr) {
                    if (current->value == runner->next->value) {
                        // remove runner->next
                        auto temp = runner->next;
                        runner->next = runner->next->next;
                        delete temp;
                        length--;
                    }

                    runner = runner->next;
                }

                current = current->next;
            }
        }

};




static void test() {
    // Helper function for pass/fail
    auto checkTestResult = [](bool condition) {
        cout << (condition ? "PASS" : "FAIL") << endl;
    };

    // Test: RemoveDuplicatesEmptyList
    {
        cout << "\n------ Test: RemoveDuplicatesEmptyList ------\n";
        
        LinkedList list(1);
        list.makeEmpty();
        
        cout << "BEFORE:    ";
        list.printList();
        
        list.removeDuplicates();
        
        cout << "AFTER:     ";
        list.printList();
        
        Node* head = list.getHead();
        checkTestResult(head == nullptr);
    }

    // Test: RemoveDuplicatesSingleElement
    {
        cout << "\n------ Test: RemoveDuplicatesSingleElement ------\n";
        
        LinkedList list(1);
        
        cout << "BEFORE:    ";
        list.printList();
        
        list.removeDuplicates();
        
        cout << "AFTER:     ";
        list.printList();
        
        Node* head = list.getHead();
        checkTestResult(head && head->value == 1);
    }

    // Test: RemoveDuplicatesNoDuplicates
    {
        cout << "\n------ Test: RemoveDuplicatesNoDuplicates ------\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        
        cout << "BEFORE:    ";
        list.printList();
        
        list.removeDuplicates();
        
        cout << "AFTER:     ";
        list.printList();
        
        Node* head = list.getHead();
        checkTestResult(head && head->value == 1);
    }

    // Test: RemoveDuplicatesHasDuplicates
    {
        cout << "\n------ Test: RemoveDuplicatesHasDuplicates ------\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(2);
        list.append(3);
        
        cout << "BEFORE:    ";
        list.printList();
        
        list.removeDuplicates();
        
        cout << "AFTER:     ";
        list.printList();
        
        // Check for duplicates
        Node* current = list.getHead();
        bool noDuplicates = true;
        
        while (current && current->next) {
            if (current->value == current->next->value) {
                noDuplicates = false;
                break;
            }
            current = current->next;
        }
        
        checkTestResult(noDuplicates);
    }
    
}



int main() {
    test();
}

