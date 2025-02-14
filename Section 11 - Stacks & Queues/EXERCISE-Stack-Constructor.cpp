#include <iostream>

using namespace std;

// Stacks are commonly implemented with either Vectors of Linked Lists.

class Node {
    public:
        int value;
        Node* next;

        Node(int value): value(value), next(nullptr) { }
};

class Stack {
    private:
		Node* top;
        int height;

    public:
        Stack(int value): height{1} {
            top = new Node(value);
        }

        ~Stack() {
            Node* temp = top;
            while (top) {
                top = top->next;
                delete temp;
                temp = top;
            }
        }

        void printStack() {
            Node* temp = top;
            while (temp) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getTop() {
            if (top == nullptr) {
                cout << "Top: nullptr" << endl;
            } else {
                cout << "Top: " << top->value << endl;
            }
        }

        void getHeight() {
            cout << "Height: " << height << endl;
        }

};



int main() {
        
    Stack* myStack = new Stack(4);

    myStack->getTop();
    myStack->getHeight();

    cout << "\nStack:\n";
    myStack->printStack();

    /*  
        EXPECTED OUTPUT:
        ----------------
        Top: 4
        Height: 1

        Stack:
        4

    */

}

