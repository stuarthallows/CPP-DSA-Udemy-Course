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
            while (temp != nullptr) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getHead() {
            if (head == nullptr) {
                cout << "Head: nullptr" << endl;
            } else {
                cout << "Head: " << head->value << endl;
            }
        }

        void getTail() {
            if (tail == nullptr) {
                cout << "Tail: nullptr" << endl;
            } else { 
                cout << "Tail: " << tail->value << endl;
            }  
        }

        void getLength() {
            cout << "Length: " << length << endl;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

        void deleteLast() {
            if (length == 0) {
                return;
            }
            
            if (length == 1) {
                delete head;
                tail = head = nullptr;
            }
            else { // length 2+
                // find previous node, i.e. where item->next == tail
                auto previous = head;
                while(previous->next != tail)
                {
                    previous = previous->next;
                }

                delete previous->next;
                previous->next = nullptr;
                tail = previous;
            }
            --length;
        }
};



int main() {
        
    LinkedList* myLinkedList = new LinkedList(1);
    myLinkedList->append(2);


    cout << "LL before deleteLast():\n";
    myLinkedList->printList();


    myLinkedList->deleteLast();
    cout << "\n\nLL after 1st deleteLast():\n";
    myLinkedList->printList();


    myLinkedList->deleteLast();
    cout << "\n\nLL after 2nd deleteLast():\n";
    myLinkedList->printList();


    myLinkedList->deleteLast();
    cout << "\n\nLL after 3rd deleteLast():\n";
    myLinkedList->printList();


    /*  
        EXPECTED OUTPUT:
    	----------------
        LL before deleteLast():
        1
        2


        LL after 1st deleteLast():
        1


        LL after 2nd deleteLast():


        LL after 3rd deleteLast():
        
    */
        
}

