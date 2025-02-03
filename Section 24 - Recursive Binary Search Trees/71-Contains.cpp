#include <iostream>

using namespace std;


class Node { 
    public: 
        int value;
        Node* left;
        Node* right;

        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};


class BinarySearchTree {
    public:
        Node* root;

    public:
        BinarySearchTree() { root = nullptr; }

        // ---------------------------------------------------
        //  Below is a helper function used by the destructor
        //  Deletes all nodes in BST
        //  Similar to DFS PostOrder in Tree Traversal section
        // ---------------------------------------------------
        void destroy(Node* currentNode) {
            if (currentNode == nullptr) return;
            if (currentNode->left) destroy(currentNode->left);
            if (currentNode->right) destroy(currentNode->right);
            delete currentNode;
        }

        ~BinarySearchTree() { destroy(root); }

        Node* getRoot() {
            return root;
        } 

        bool insert(int value) {
            Node* newNode = new Node(value);
            if (root == nullptr) {
                root = newNode;
                return true;
            }
            Node* temp = root;
            while(true) {
                if (newNode->value == temp->value) return false;
                if (newNode->value < temp->value) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }
            }
        }


        //   +===================================================+
        //   |              WRITE YOUR CODE HERE                 |
        //   | Description:                                      |
        //   | - Recursively checks if a binary search tree      |
        //   |   contains a node with the given value.           |
        //   |                                                   |
        //   | Parameters:                                       |
        //   | - currentNode: The node currently being checked.  |
        //   | - value: The value being searched for.            |
        //   |                                                   |
        //   | Return:                                           |
        //   | - Returns true if the value is found in the tree; |
        //   |   otherwise, returns false.                       |
        //   |                                                   |
        //   | Behavior:                                         |
        //   | - Starts the search from the currentNode and      |
        //   |   traverses the tree down to its children based   |
        //   |   on the value being greater or lesser than the   |
        //   |   currentNode's value, following BST properties.  |
        //   | - If a null node is reached, the value is not     |
        //   |   present in the tree and false is returned.      |
        //   | - If the node with the value is found, returns    |
        //   |   true.                                           |
        //   +===================================================+
        bool rContains(Node* currentNode, int value) { 
            if (currentNode == nullptr) {
                return false;
            }
            if (currentNode->value == value) {
                return true;
            }
            if (currentNode->value > value) {
                return rContains(currentNode->left, value); 
            }
            return rContains(currentNode->right, value); 
        } 

        bool rContains(int value) { 
            return rContains(root, value); 
        } 

};

static void test() {
    {
        cout << "\n----- Test: rContains in Empty Tree -----\n";
        BinarySearchTree bst;
        int valueToSearch = 42;
        cout << "Searching for value " << valueToSearch
             << " in an empty tree - EXPECTED: false\n";
        cout << (bst.rContains(valueToSearch) ? "FAIL\n" : "PASS\n");
    }

    {
        cout << "\n----- Test: rContains with One Element -----\n";
        BinarySearchTree bst;
        bst.insert(10);
        cout << "Inserting 10, then checking if it's contained - EXPECTED: true\n";
        cout << (bst.rContains(10) ? "PASS\n" : "FAIL\n");
        cout << "Checking for non-existent value 5 - EXPECTED: false\n";
        cout << (bst.rContains(5) ? "FAIL\n" : "PASS\n");
    }

    {
        cout << "\n----- Test: rContains with Multiple Elements -----\n";
        BinarySearchTree bst;
        bst.insert(10);
        bst.insert(5);
        bst.insert(15);
        cout << "Inserting 10, 5, 15, then checking if they're contained - EXPECTED: true\n";
        cout << (bst.rContains(10) && bst.rContains(5) && bst.rContains(15) ? "PASS\n" : "FAIL\n");
        cout << "Checking for non-existent value 1 - EXPECTED: false\n";
        cout << (bst.rContains(1) ? "FAIL\n" : "PASS\n");
    }

    {
        cout << "\n----- Test: rContains with Duplicate Insert -----\n";
        BinarySearchTree bst;
        bst.insert(10);
        bst.insert(10); // Duplicate insert
        cout << "Inserting 10 twice, then checking if it's contained - EXPECTED: true\n";
        cout << (bst.rContains(10) ? "PASS\n" : "FAIL\n");
        cout << "Checking for non-existent value 15 - EXPECTED: false\n";
        cout << (bst.rContains(15) ? "FAIL\n" : "PASS\n");
    }

    {
        cout << "\n----- Test: rContains with Complex Structure -----\n";
        BinarySearchTree bst;
        bst.insert(50);
        bst.insert(30);
        bst.insert(70);
        bst.insert(20);
        bst.insert(40);
        bst.insert(60);
        bst.insert(80);
        cout << "Inserting 50, 30, 70, 20, 40, 60, 80, then checking if they're contained - EXPECTED: true\n";
        cout << (bst.rContains(50) && bst.rContains(30) && bst.rContains(70) &&
                 bst.rContains(20) && bst.rContains(40) && bst.rContains(60) &&
                 bst.rContains(80) ? "PASS\n" : "FAIL\n");
        cout << "Checking for non-existent value 10 - EXPECTED: false\n";
        cout << (bst.rContains(10) ? "FAIL\n" : "PASS\n");
    }
}

int main() {
    test();
}
