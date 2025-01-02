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
        //   | - Convert binary number in list to decimal           |
        //   | - Return type: int                                   |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Use a single pointer: 'current'                    |
        //   | - Initialize an integer 'num' to 0                   |
        //   | - Loop through the list                              |
        //   | - Use the formula: num = num * 2 + current->value    |
        //   | - Return 'num' as the decimal value                  |
        //   +======================================================+
        int binaryToDecimal() {
            if (length == 0) {
                return 0;
            }

            auto num{0};

            auto current{head};
            while (current != nullptr) {
                num = num * 2 + current->value;
                current = current->next;
            }

            return num;
        }
};


static void test() {
    // Helper function for pass/fail
    auto checkTestResult = [](bool condition) {
        cout << (condition ? "PASS" : "FAIL") << endl;
    };

    // Test: BinaryToDecimalEmptyList
    {
        cout << "\n------ Test: BinaryToDecimalEmptyList ------\n";
        
        LinkedList list(1);
        list.makeEmpty();
        
        cout << "BINARY:    ";
        list.printList();
        
        int decimal = list.binaryToDecimal();
        
        cout << "DECIMAL:   " << decimal << endl;
        
        checkTestResult(decimal == 0);
    }

    // Test: BinaryToDecimalSingleElement
    {
        cout << "\n------ Test: BinaryToDecimalSingleElement ------\n";
        
        LinkedList list(1);
        
        cout << "BINARY:    ";
        list.printList();
        
        int decimal = list.binaryToDecimal();
        
        cout << "DECIMAL:   " << decimal << endl;
        
        checkTestResult(decimal == 1);
    }

    // Test: BinaryToDecimalMultipleElements
    {
        cout << "\n------ Test: BinaryToDecimalMultipleElements ------\n";
        
        LinkedList list(1);
        list.append(0);
        list.append(1);
        list.append(1);
        
        cout << "BINARY:    ";
        list.printList();
        
        int decimal = list.binaryToDecimal();
        
        cout << "DECIMAL:   " << decimal << endl;
        
        checkTestResult(decimal == 11);
    }

    // Test: BinaryToDecimalAllZeros
    {
        cout << "\n------ Test: BinaryToDecimalAllZeros ------\n";
        
        LinkedList list(0);
        list.append(0);
        list.append(0);
        list.append(0);
        
        cout << "BINARY:    ";
        list.printList();
        
        int decimal = list.binaryToDecimal();
        
        cout << "DECIMAL:   " << decimal << endl;
        
        checkTestResult(decimal == 0);
    }

    // Test: BinaryToDecimalAllOnes
    {
        cout << "\n------ Test: BinaryToDecimalAllOnes ------\n";
        
        LinkedList list(1);
        list.append(1);
        list.append(1);
        list.append(1);
        
        cout << "BINARY:    ";
        list.printList();
        
        int decimal = list.binaryToDecimal();
        
        cout << "DECIMAL:   " << decimal << endl;
        
        checkTestResult(decimal == 15);
    }
}

int main() {
    test();
}


