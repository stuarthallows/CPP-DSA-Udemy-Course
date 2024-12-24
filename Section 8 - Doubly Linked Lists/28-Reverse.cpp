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
        //   | - This is the reverse method.                       |
        //   | - It reverses the entire doubly linked list.        |
        //   | - Return type: void                                 |
        //   |                                                     |
        //   | Tips:                                               |
        //   | - Create two pointers: current and temp.            |
        //   | - Loop through the list swapping next and prev      |
        //   |   for each node.                                    |
        //   | - After loop, swap head and tail pointers.          |
        //   | - Check output from Test.cpp in "User logs".        |
        //   +=====================================================+
        void reverse() {

        }
};

static void test() {

    // Test: Reverse Single Node
    {
        cout << "\n----- Test: Reverse Single Node -----\n";
        DoublyLinkedList list(1);
        cout << "DLL before reversing:\n";
        list.printList();
        list.reverse();
        cout << "DLL after reversing:\n";
        list.printList();
        int headValue = list.getHead()->value;
        int tailValue = list.getTail()->value;
        cout << "Head value after reversing: " << headValue << " - EXPECTED: 1\n";
        cout << "Tail value after reversing: " << tailValue << " - EXPECTED: 1\n";
        cout << ((headValue == 1 && tailValue == 1) ? "PASS\n" : "FAIL\n");
    }

    // Test: Reverse Two Nodes
    {
        cout << "\n----- Test: Reverse Two Nodes -----\n";
        DoublyLinkedList list(1);
        list.append(2);
        cout << "DLL before reversing:\n";
        list.printList();
        list.reverse();
        cout << "DLL after reversing:\n";
        list.printList();
        int headValue = list.getHead()->value;
        int tailValue = list.getTail()->value;
        cout << "Head value after reversing: " << headValue << " - EXPECTED: 2\n";
        cout << "Tail value after reversing: " << tailValue << " - EXPECTED: 1\n";
        cout << ((headValue == 2 && tailValue == 1) ? "PASS\n" : "FAIL\n");
    }

    // Test: Reverse Multiple Nodes
    {
        cout << "\n----- Test: Reverse Multiple Nodes -----\n";
        DoublyLinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(4);
        cout << "DLL before reversing:\n";
        list.printList();
        list.reverse();
        cout << "DLL after reversing:\n";
        list.printList();
        int headValue = list.getHead()->value;
        int tailValue = list.getTail()->value;
        int headNextValue = list.getHead()->next->value;
        int tailPrevValue = list.getTail()->prev->value;
        cout << "Head value after reversing: " << headValue << " - EXPECTED: 4\n";
        cout << "Tail value after reversing: " << tailValue << " - EXPECTED: 1\n";
        cout << "Value after head after reversing: " << headNextValue << " - EXPECTED: 3\n";
        cout << "Value before tail after reversing: " << tailPrevValue << " - EXPECTED: 2\n";
        bool pass = headValue == 4 && tailValue == 1 && headNextValue == 3 && tailPrevValue == 2;
        cout << (pass ? "PASS\n" : "FAIL\n");
    }
    
}

int main() {
    test();
}
