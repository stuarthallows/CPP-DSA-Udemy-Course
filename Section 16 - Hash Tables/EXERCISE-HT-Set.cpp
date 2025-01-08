#include <iostream>

using namespace std;


class Node {
    public:
        string key;
        int value;
        Node* next;

        Node(string key, int value) {
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};

class HashTable {
    private:
        static const int SIZE = 7;
        Node* dataMap[SIZE];

        int hash(string key) {
            int hash = 0;
            for (int i = 0; i < key.length(); i++) {
                int asciiValue = int(key[i]);
                hash = (hash + asciiValue *  23) % SIZE;
            }
            return hash;
        }

    public:
        // ---------------------------------------------------
        //  Destructor code is similar to keys() function
        //  Watch that video to help understand how this works
        // ---------------------------------------------------
        ~HashTable() {
            for(int i = 0; i < SIZE; i++) {
                Node* head = dataMap[i];
                Node* temp = head;
                while (head) {
                    head = head->next;
                    delete temp;
                    temp = head;
                }
            }
        }
        
        void printTable() {
            for(int i = 0; i < SIZE; i++) {
                cout << i << ":" << endl;
                if(dataMap[i]) {
                    Node* temp = dataMap[i];
                    while (temp) {
                        cout << "   {" << temp->key << ", " << temp->value << "}" << endl;
                        temp = temp->next;
                    }
                }
            }
        }
        
        //   +=====================================================+
        //   |                 WRITE YOUR CODE HERE                |
        //   | Description:                                        |
        //   | - This method sets a key-value pair in the hash     |
        //   |   table.                                            |
        //   | - It first hashes the key to find the index.        |
        //   | - Creates a new node and inserts it at the index.   |
        //   | - Return type: void                                 |
        //   |                                                     |
        //   | Tips:                                               |
        //   | - Use the 'hash' function to get the index.         |
        //   | - If the index is empty, directly set the node.     |
        //   | - If not, traverse to the end and set the node.     |
        //   | - 'dataMap' is the array to hold the key-value      |
        //   |   pairs.                                            |
        //   | - Check output from Test.cpp in "User logs".        |
        //   +=====================================================+
        void set(string key, int value) {
            auto index = hash(key);
            auto newNode = new Node(key, value);
            
            if (!dataMap[index]) {
                dataMap[index] = newNode;
                return;
            }

            Node* temp = dataMap[index];
            while(temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        int get(string key) {
            int index = hash(key);
            Node* temp = dataMap[index];
            while (temp != nullptr) {
                if (temp->key == key) return temp->value;
                temp = temp->next;
            }
            return 0;
        }
};


int main() {

    HashTable* myHashTable = new HashTable();

    myHashTable->set("nails", 100);
    myHashTable->set("tile", 50);
    myHashTable->set("lumber", 80);

    myHashTable->set("bolts", 200);
    myHashTable->set("screws", 140);

    myHashTable->printTable();

    /*
        EXPECTED OUTPUT:
        ----------------
        0:
        1:
        2:
        3:
           {screws, 140}
        4:
           {bolts, 200}
        5:
        6:
           {nails, 100}
           {tile, 50}
           {lumber, 80}

    */  

}

