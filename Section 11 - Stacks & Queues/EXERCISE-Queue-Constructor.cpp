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

class Queue {
    private:
        Node* first;
        Node* last;
        int length;

    public:
        Queue(int value) {
            auto newNode = new Node(value);

            first = last = newNode;
            length = 1;
        }

        ~Queue() {
            Node* temp = first;
            while (first) {
                first = first->next;
                delete temp;
                temp = first;
            }
        }

        void printQueue() {
            if (length == 0) {
                cout << "Queue: empty" << endl;
                return;
            }
            Node* temp = first;
            cout << "Queue: ";
            while (temp) {
                cout << temp->value;
                temp = temp->next;
                if (temp) {
                    cout << " -> ";
                }
            }
            cout << endl;
        }


        Node* getFirst() {
            return first;
        }

        Node* getLast() {
            return last;
        }

        int getLength() {
            return length;
        }

        bool isEmpty() {
            if (length == 0) return true;
            return false;
        }      
};




int main() {
        
    Queue* myQueue = new Queue(7);

    myQueue->getFirst();
    myQueue->getLast();
    myQueue->getLength();

    cout << "\nQueue:\n";
    myQueue->printQueue();

    /*  
        EXPECTED OUTPUT:
        ----------------
        First: 7
        Last: 7
        Length: 1

        Queue:
        7

    */    

}

