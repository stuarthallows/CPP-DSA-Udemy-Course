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
                
        Node* rInsert(Node* currentNode, int value) {
            if (currentNode == nullptr) return new Node(value);
        
            if (value < currentNode->value) {
                currentNode->left = rInsert(currentNode->left, value);
            } else if (value > currentNode->value) {
                currentNode->right = rInsert(currentNode->right, value);
            } 
            return currentNode;
        }
        void rInsert(int value) { 
            if (root == nullptr) root = new Node(value);
            rInsert(root, value); 
        } 

        //   +===================================================+
        //   |              WRITE YOUR CODE HERE                 |
        //   | Description:                                      |
        //   | - Finds the minimum value in a binary search tree |
        //   |   by traversing down the left children of nodes.  |
        //   |                                                   |
        //   | Parameters:                                       |
        //   | - currentNode: The starting node of the tree.     |
        //   |                                                   |
        //   | Return:                                           |
        //   | - Returns the value of the leftmost node, which   |
        //   |   represents the minimum value in the tree.       |
        //   |                                                   |
        //   | Behavior:                                         |
        //   | - The method iteratively moves to the left child  |
        //   |   of each node, reaching the leftmost node which  |
        //   |   does not have a left child.                     |
        //   | - This leftmost node contains the minimum value   |
        //   |   in the tree, following the properties of a BST. |
        //   +===================================================+
        int minValue(Node* currentNode) {
            while(currentNode->left != nullptr) {
                currentNode = currentNode->left;
            }
            return currentNode->value;
        }
};

static void test() {
    // Test: Min Value in an Empty Tree
    {
        cout << "\n----- Test: Min Value in Empty Tree -----\n";
        BinarySearchTree bst;
        if (bst.root == nullptr) {
            cout << "PASS (Tree is empty)\n";
        } else {
            cout << "FAIL\n";
        }
    }

    // Test: Min Value with One Element
    {
        cout << "\n----- Test: Min Value with One Element -----\n";
        BinarySearchTree bst;
        bst.rInsert(42);
        cout << "Inserting value 42 and checking minimum - EXPECTED: 42\n";
        cout << (bst.minValue(bst.getRoot()) == 42 ? "PASS\n" : "FAIL\n");
    }

    // Test: Min Value with Multiple Elements
    {
        cout << "\n----- Test: Min Value with Multiple Elements -----\n";
        BinarySearchTree bst;
        bst.rInsert(50);
        bst.rInsert(30);
        bst.rInsert(70);
        bst.rInsert(20);
        bst.rInsert(40);
        bst.rInsert(60);
        bst.rInsert(10); // Minimum value
        cout << "Inserting multiple values, minimum expected: 10\n";
        cout << (bst.minValue(bst.getRoot()) == 10 ? "PASS\n" : "FAIL\n");
    }

    // Test: Subtree Min Values
    {
        cout << "\n----- Test: Subtree Min Values -----\n";
        BinarySearchTree bst;
        bst.rInsert(50);
        bst.rInsert(30);
        bst.rInsert(70);
        bst.rInsert(20);
        bst.rInsert(40);
        bst.rInsert(60);
        bst.rInsert(80);

        cout << "Checking minimum value in left subtree (EXPECTED: 20)\n";
        cout << (bst.minValue(bst.getRoot()->left) == 20 ? "PASS\n" : "FAIL\n");
        
        cout << "Checking minimum value in right subtree (EXPECTED: 60)\n";
        cout << (bst.minValue(bst.getRoot()->right) == 60 ? "PASS\n" : "FAIL\n");
    }

    // Test: Min Value with Negative Elements
    {
        cout << "\n----- Test: Min Value with Negative Elements -----\n";
        BinarySearchTree bst;
        bst.rInsert(-20);
        bst.rInsert(-10);
        bst.rInsert(-30); // Minimum value
        bst.rInsert(0);
        cout << "Inserting negative values, minimum expected: -30\n";
        cout << (bst.minValue(bst.getRoot()) == -30 ? "PASS\n" : "FAIL\n");
    }
}

int main() {
    test();
}
