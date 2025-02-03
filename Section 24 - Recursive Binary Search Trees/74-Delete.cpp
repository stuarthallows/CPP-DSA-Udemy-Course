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
        
        bool rContains(Node* currentNode, int value) {
            if (currentNode == nullptr) return false;
            
            if (currentNode->value == value) return true;
            
            if (value < currentNode->value) {
                return rContains(currentNode->left, value);
            } else {
                return rContains(currentNode->right, value);
            }
        }
        bool rContains(int value) { 
            return rContains(root, value); 
        } 

        int minValue(Node* currentNode) {
            while (currentNode->left != nullptr) {
                currentNode = currentNode->left;
            }
            return currentNode->value;
        } 
              
        //   +===================================================+
        //   |              WRITE YOUR CODE HERE                 |
        //   | Description:                                      |
        //   | - Deletes a node with a specific value from a     |
        //   |   binary search tree (BST) and maintains the      |
        //   |   BST properties after deletion.                  |
        //   |                                                   |
        //   | Parameters:                                       |
        //   | - currentNode: The node currently being examined. |
        //   | - value: The value of the node to be deleted.     |
        //   |                                                   |
        //   | Return:                                           |
        //   | - The modified tree's root node after deletion.   |
        //   |                                                   |
        //   | Behavior:                                         |
        //   | - If the value is less/more than the current node,|
        //   |   recursively search in the left/right subtree.   |
        //   | - If the node to delete is found and has no child,|
        //   |   delete the node and return null.                |
        //   | - If the node has one child, delete the node and  |
        //   |   return the child.                               |
        //   | - If the node has two children, find the minimum  |
        //   |   value in the right subtree, replace the node's  |
        //   |   value with this minimum value, and then delete  |
        //   |   the minimum value node in the right subtree.    |
        //   +===================================================+
        Node* deleteNode(Node* currentNode, int value) {
            if (currentNode == nullptr) return nullptr;

            if (value < currentNode->value) {
                // Traverse left
                currentNode->left = deleteNode(currentNode->left, value);
            } else if (value > currentNode->value) {
                // Traverse right
                currentNode->right = deleteNode(currentNode->right, value);
            } else {
                // 1. When we have a leaf node
                if (currentNode->left == nullptr && currentNode->right == nullptr) {
                    delete(currentNode);
                    return nullptr;
                }

                // 2. When we have a child node on the right and it's open on the left
                else if (currentNode->left == nullptr && currentNode->right != nullptr) {
                    Node* temp = currentNode->right;
                    delete(currentNode);
                    return temp;
                }

                // 3. When we have a child node on the left and it's open on the right
                else if (currentNode->left != nullptr && currentNode->right == nullptr) {
                    Node* temp = currentNode->left;
                    delete(currentNode);
                    return temp;                    
                }

                // 4. When we have child nodes on each side
                else {
                    int subTreeMin = minValue(currentNode->right);
                    currentNode->value = subTreeMin;
                    currentNode->right = deleteNode(currentNode->right, subTreeMin);
                }
            }

            return currentNode;
        }

        void deleteNode(int value) { root = deleteNode(root, value); }

};

static void test() {
    // Test: Delete Node from an Empty Tree
    {
        cout << "\n----- Test: Delete Node from Empty Tree -----\n";
        BinarySearchTree bst;
        bst.deleteNode(42); // Attempt to delete from an empty tree
        cout << "Attempting to delete value 42 from an empty tree.\n";
        cout << (bst.getRoot() == nullptr ? "PASS\n" : "FAIL\n");
    }

    // Test: Delete Leaf Node
    {
        cout << "\n----- Test: Delete Leaf Node -----\n";
        BinarySearchTree bst;
        bst.rInsert(50);
        bst.rInsert(30);
        bst.rInsert(70);
        bst.rInsert(20); // Leaf node
        bst.deleteNode(20); // Deleting the leaf node
        cout << "Deleting leaf node 20.\n";
        cout << (!bst.rContains(20) ? "PASS\n" : "FAIL\n");
    }

    // Test: Delete Node with One Child
    {
        cout << "\n----- Test: Delete Node with One Child -----\n";
        BinarySearchTree bst;
        bst.rInsert(50);
        bst.rInsert(30);
        bst.rInsert(70);
        bst.rInsert(20); // Leaf node
        bst.rInsert(25); // Node with one child
        bst.deleteNode(20); // Deleting node with one child
        cout << "Deleting node 20, which has one child 25.\n";
        cout << (!bst.rContains(20) && bst.rContains(25) ? "PASS\n" : "FAIL\n");
    }

    // Test: Delete Node with Two Children
    {
        cout << "\n----- Test: Delete Node with Two Children -----\n";
        BinarySearchTree bst;
        bst.rInsert(50);
        bst.rInsert(30);
        bst.rInsert(70);
        bst.rInsert(20);
        bst.rInsert(40);
        bst.rInsert(60);
        bst.rInsert(80);
        bst.deleteNode(30); // Node with two children
        cout << "Deleting node 30, which has two children (20 and 40).\n";
        cout << (!bst.rContains(30) && bst.rContains(20) && bst.rContains(40) ? "PASS\n" : "FAIL\n");
    }

    // Test: Delete Root Node
    {
        cout << "\n----- Test: Delete Root Node -----\n";
        BinarySearchTree bst;
        bst.rInsert(50);
        bst.rInsert(30);
        bst.rInsert(70);
        bst.deleteNode(50); // Deleting the root node
        cout << "Deleting root node 50.\n";
        cout << (!bst.rContains(50) ? "PASS\n" : "FAIL\n");
    }
}

int main() {
    test();
}
