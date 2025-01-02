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
        //   | - This is the swapFirstLast function.               |
        //   | - It swaps the values of the first and last nodes   |
        //   |   in the doubly linked list.                        |
        //   | - Return type: void                                 |
        //   |                                                     |
        //   | Tips:                                               |
        //   | - Check if the list has less than 2 nodes. If so,   |
        //   |   just return; nothing to swap.                     |
        //   | - Use a temporary variable to store the value of    |
        //   |   the head node.                                    |
        //   | - Assign the value of the tail node to the head     |
        //   |   node.                                             |
        //   | - Assign the stored head node value to the tail.    |
        //   | - Check output from Test.cpp in "User logs".        |
        //   +=====================================================+
        void swapFirstLast() {

        }
};

static void test() {

    // Test: Swap First and Last with Single Node
    {
        cout << "\n----- Test: Swap First and Last with Single Node -----\n";
        DoublyLinkedList list(1);
        cout << "DLL before swapping first and last:\n";
        list.printList();
        list.swapFirstLast();
        cout << "DLL after swapping first and last:\n";
        list.printList();
        int headValue = list.getHead()->value;
        int tailValue = list.getTail()->value;
        cout << "Head value after swapping: " << headValue << " - EXPECTED: 1\n";
        cout << "Tail value after swapping: " << tailValue << " - EXPECTED: 1\n";
        cout << ((headValue == 1 && tailValue == 1) ? "PASS\n" : "FAIL\n");
    }

    // Test: Swap First and Last with Two Nodes
    {
        cout << "\n----- Test: Swap First and Last with Two Nodes -----\n";
        DoublyLinkedList list(1);
        list.append(2);
        cout << "DLL before swapping first and last:\n";
        list.printList();
        list.swapFirstLast();
        cout << "DLL after swapping first and last:\n";
        list.printList();
        int headValue = list.getHead()->value;
        int tailValue = list.getTail()->value;
        cout << "Head value after swapping: " << headValue << " - EXPECTED: 2\n";
        cout << "Tail value after swapping: " << tailValue << " - EXPECTED: 1\n";
        cout << ((headValue == 2 && tailValue == 1) ? "PASS\n" : "FAIL\n");
    }

    // Test: Swap First and Last with Multiple Nodes
    {
        cout << "\n----- Test: Swap First and Last with Multiple Nodes -----\n";
        DoublyLinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(4);
        cout << "DLL before swapping first and last:\n";
        list.printList();
        list.swapFirstLast();
        cout << "DLL after swapping first and last:\n";
        list.printList();
        int headValue = list.getHead()->value;
        int tailValue = list.getTail()->value;
        int headNextValue = list.getHead()->next->value;
        int tailPrevValue = list.getTail()->prev->value;
        cout << "Head value after swapping: " << headValue << " - EXPECTED: 4\n";
        cout << "Tail value after swapping: " << tailValue << " - EXPECTED: 1\n";
        cout << "Value after head after swapping: " << headNextValue << " - EXPECTED: 2\n";
        cout << "Value before tail after swapping: " << tailPrevValue << " - EXPECTED: 3\n";
        bool pass = headValue == 4 && tailValue == 1 && headNextValue == 2 && tailPrevValue == 3;
        cout << (pass ? "PASS\n" : "FAIL\n");
    }
    
}

int main() {
    test();
}
