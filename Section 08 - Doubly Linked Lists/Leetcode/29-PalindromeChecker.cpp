#include <iostream>

using namespace std;

class Node { 
    public: 
        int value;
        Node* next;
        Node* prev;
    
        Node(int value) {
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
        int length;
    
    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
    
        ~DoublyLinkedList() {
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
                cout << "empty" << endl;
                return;
            }
            while (temp->next != nullptr) {
                cout << temp->value << " <-> ";
                temp = temp->next;
            }
            cout << temp->value << endl;
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

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }

        //   +=====================================================+
        //   |                 WRITE YOUR CODE HERE                |
        //   | Description:                                        |
        //   | - This is the isPalindrome method.                  |
        //   | - It checks if the list is a palindrome or not.     |
        //   | - Return type: bool                                 |
        //   |                                                     |
        //   | Tips:                                               |
        //   | - A list with 0 or 1 node is a palindrome.          |
        //   | - Create two pointers: forwardNode and backwardNode.|
        //   | - Loop from the start to the middle of the list.    |
        //   | - Compare forwardNode and backwardNode values.      |
        //   | - If any pair is not equal, return false.           |
        //   | - Otherwise, return true.                           |
        //   | - Check output from Test.cpp in "User logs".        |
        //   +=====================================================+
        bool isPalindrome() {
            return false;
        }
};

static void test() {

    // Test: Is Palindrome with Single Node
    {
        cout << "\n----- Test: Is Palindrome with Single Node -----\n";
        DoublyLinkedList list(1);
        cout << "DLL:\n";
        list.printList();
        bool result = list.isPalindrome();
        cout << "Is Palindrome: " << (result ? "true" : "false") << " - EXPECTED: true\n";
        cout << (result ? "PASS\n" : "FAIL\n");
    }

    // Test: Is Palindrome with Two Nodes
    {
        cout << "\n----- Test: Is Palindrome with Two Nodes -----\n";

        DoublyLinkedList list(1);
        list.append(1);
        cout << "DLL (equal values):\n";
        list.printList();
        bool result1 = list.isPalindrome();
        cout << "Is Palindrome: " << (result1 ? "true" : "false") << " - EXPECTED: true\n";
        cout << (result1 ? "PASS\n" : "FAIL\n");

        DoublyLinkedList list2(1);
        list2.append(2);
        cout << "\nDLL (different values):\n";
        list2.printList();
        bool result2 = list2.isPalindrome();
        cout << "Is Palindrome: " << (result2 ? "true" : "false") << " - EXPECTED: false\n";
        cout << (result2 ? "FAIL\n" : "PASS\n");
    }

    // Test: Is Palindrome with Multiple Nodes
    {
        cout << "\n----- Test: Is Palindrome with Multiple Nodes -----\n";

        DoublyLinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(2);
        list.append(1);
        cout << "DLL (palindrome):\n";
        list.printList();
        bool result1 = list.isPalindrome();
        cout << "Is Palindrome: " << (result1 ? "true" : "false") << " - EXPECTED: true\n";
        cout << (result1 ? "PASS\n" : "FAIL\n");

        DoublyLinkedList list2(1);
        list2.append(2);
        list2.append(3);
        list2.append(3);
        list2.append(2);
        cout << "\nDLL (not palindrome):\n";
        list2.printList();
        bool result2 = list2.isPalindrome();
        cout << "Is Palindrome: " << (result2 ? "true" : "false") << " - EXPECTED: false\n";
        cout << (result2 ? "FAIL\n" : "PASS\n");
    }
    
}

int main() {
    test();
}
