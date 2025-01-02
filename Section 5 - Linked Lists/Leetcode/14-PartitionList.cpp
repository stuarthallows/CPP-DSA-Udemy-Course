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

        //   +======================================================+
        //   |                 WRITE YOUR CODE HERE                 |
        //   | Description:                                         |
        //   | - Partition list around value x                      |
        //   | - Return type: void                                  |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Create two dummy nodes for two new lists           |
        //   | - One list for nodes less than x                     |
        //   | - Another list for nodes greater or equal to x       |
        //   | - Loop through original list                         |
        //   | - Assign nodes to new lists based on value           |
        //   | - Merge the two new lists                            |
        //   | - Update the original list's head                    |
        //   +======================================================+
        void partitionList(int x) {
            if (length < 2) {
                return;
            }

            Node* lower{nullptr};
            Node* lowerHead{nullptr};
            Node* upper{nullptr};
            Node* upperHead{nullptr};

            Node* current = head;
            while(current != nullptr) {
                if (current->value < x) {
                    if (lower == nullptr) {
                        lower = current;
                        lowerHead = current;
                    } else {
                        lower->next = current;
                        lower = lower->next;
                    }
                } else { // current->value >= x
                    if (upper == nullptr) {
                        upper = current;
                        upperHead = current;
                    } else {
                        upper->next = current;
                        upper = upper->next;
                    }
                }

                current = current->next;
            }

            if (lowerHead != nullptr && upperHead != nullptr) {
                lower->next = upperHead;
                upper->next = nullptr;
            } else if (lowerHead == nullptr) {
                upperHead = head;
                upper->next = nullptr;
            } else if (upperHead == nullptr) {
                lowerHead = head;
                lower->next = nullptr;
            }
        }
};




static void test() {
    // Helper function to check pass/fail
    auto checkTestResult = [](bool condition) {
        cout << (condition ? "PASS" : "FAIL") << endl;
    };

    // Test: PartitionEmptyList
    {
        cout << "\n------ Test: PartitionEmptyList ------\n";
        
        LinkedList list(1);
        list.makeEmpty();
        
        cout << "BEFORE:    ";
        list.printList();
        
        cout << "partitionList(3)\n";
        cout << "EXPECTED:  empty\n";
        
        list.partitionList(3);
        
        cout << "ACTUAL:    ";
        list.printList();
        
        Node* head = list.getHead();
        checkTestResult(head == nullptr);
    }

    // Test: PartitionSingleElement
    {
        cout << "\n------ Test: PartitionSingleElement ------\n";
        
        LinkedList list(1);
        
        cout << "BEFORE:    ";
        list.printList();
        
        cout << "partitionList(3)\n";
        cout << "EXPECTED:  1\n";
        
        list.partitionList(3);
        
        cout << "ACTUAL:    ";
        list.printList();
        
        Node* head = list.getHead();
        checkTestResult(head && head->value == 1);
    }

    // Test: PartitionAllLessThanX
    {
        cout << "\n------ Test: PartitionAllLessThanX ------\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        
        cout << "BEFORE:    ";
        list.printList();
        
        cout << "partitionList(4)\n";
        cout << "EXPECTED:  1 -> 2 -> 3\n";
        
        list.partitionList(4);
        
        cout << "ACTUAL:    ";
        list.printList();
        
        Node* head = list.getHead();
        checkTestResult(head && head->value == 1);
    }

    // Test: PartitionMixedNumbers
    {
        cout << "\n------ Test: PartitionMixedNumbers ------\n";
        
        LinkedList list(1);
        list.append(4);
        list.append(3);
        list.append(2);
        list.append(5);
        list.append(2);
        
        cout << "BEFORE:    ";
        list.printList();
        
        cout << "partitionList(3)\n";
        cout << "EXPECTED:  1 -> 2 -> 2 -> 4 -> 3 -> 5\n";
        
        list.partitionList(3);
        
        cout << "ACTUAL:    ";
        list.printList();
        
        // Check if the list is partitioned correctly
        Node* current = list.getHead();
        bool isPartitioned = true;
        bool crossedPartitionValue = false;
        
        while (current && current->next) {
            if (current->value >= 3) {
                crossedPartitionValue = true;
            }
            if (crossedPartitionValue && current->value < 3) {
                isPartitioned = false;
                break;
            }
            current = current->next;
        }

        
        checkTestResult(isPartitioned);
    }
}

int main() {
    test();
}

