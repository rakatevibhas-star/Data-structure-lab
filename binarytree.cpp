#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// ─── Node Structure ───────────────────────────────────────────────────────────
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// ─── Binary Search Tree Class ─────────────────────────────────────────────────
class BST {
private:
    Node* root;

    // Insert helper (recursive)
    Node* insert(Node* node, int val) {
        if (node == nullptr)
            return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;
    }

    // Search helper (recursive)
    bool search(Node* node, int val) {
        if (node == nullptr) return false;
        if (val == node->data) return true;
        if (val < node->data) return search(node->left, val);
        return search(node->right, val);
    }

    // Find minimum value node (used in deletion)
    Node* findMin(Node* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    // Delete helper (recursive)
    Node* deleteNode(Node* node, int val) {
        if (node == nullptr) return nullptr;

        if (val < node->data) {
            node->left = deleteNode(node->left, val);
        } else if (val > node->data) {
            node->right = deleteNode(node->right, val);
        } else {
            // Case 1: No children (leaf node)
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            // Case 2: One child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: Two children — replace with in-order successor
            Node* successor = findMin(node->right);
            node->data = successor->data;
            node->right = deleteNode(node->right, successor->data);
        }
        return node;
    }

    // ── Traversals ──────────────────────────────────────────────────────────
    void inOrder(Node* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void preOrder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(Node* node) {
        if (node == nullptr) return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }

    // ── Utility Helpers ─────────────────────────────────────────────────────
    int height(Node* node) {
        if (node == nullptr) return -1;
        return 1 + max(height(node->left), height(node->right));
    }

    int countNodes(Node* node) {
        if (node == nullptr) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    void freeTree(Node* node) {
        if (node == nullptr) return;
        freeTree(node->left);
        freeTree(node->right);
        delete node;
    }

    // Print tree sideways (right → root → left)
    void printTree(Node* node, int space, int gap = 5) {
        if (node == nullptr) return;
        space += gap;
        printTree(node->right, space, gap);
        cout << endl;
        for (int i = gap; i < space; i++) cout << " ";
        cout << node->data << "\n";
        printTree(node->left, space, gap);
    }

public:
    BST() : root(nullptr) {}

    ~BST() { freeTree(root); }

    void insert(int val)        { root = insert(root, val); }
    bool search(int val)        { return search(root, val); }
    void deleteNode(int val)    { root = deleteNode(root, val); }

    void inOrder()   { cout << "In-order   (sorted): "; inOrder(root);   cout << "\n"; }
    void preOrder()  { cout << "Pre-order           : "; preOrder(root);  cout << "\n"; }
    void postOrder() { cout << "Post-order          : "; postOrder(root); cout << "\n"; }

    // Level-order (BFS) traversal
    void levelOrder() {
        if (root == nullptr) return;
        cout << "Level-order (BFS)   : ";
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front(); q.pop();
            cout << curr->data << " ";
            if (curr->left)  q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << "\n";
    }

    int  height()     { return height(root); }
    int  countNodes() { return countNodes(root); }
    void printTree()  { printTree(root, 0); cout << "\n"; }
};

// ─── Main ─────────────────────────────────────────────────────────────────────
int main() {
    BST tree;

    cout << "=== Inserting: 50 25 75 12 37 62 88 ===\n";
    for (int val : {50, 25, 75, 12, 37, 62, 88})
        tree.insert(val);

    cout << "\nTree structure (rotated 90°, right → root → left):\n";
    tree.printTree();

    cout << "Height     : " << tree.height()     << "\n";
    cout << "Node count : " << tree.countNodes() << "\n\n";

    cout << "=== Traversals ===\n";
    tree.inOrder();
    tree.preOrder();
    tree.postOrder();
    tree.levelOrder();

    cout << "\n=== Search ===\n";
    cout << "Search 37  : " << (tree.search(37)  ? "Found" : "Not found") << "\n";
    cout << "Search 100 : " << (tree.search(100) ? "Found" : "Not found") << "\n";

    cout << "\n=== Delete 25 (node with two children) ===\n";
    tree.deleteNode(25);
    tree.inOrder();
    tree.printTree();

    cout << "=== Delete 12 (leaf node) ===\n";
    tree.deleteNode(12);
    tree.inOrder();

    cout << "\n=== Delete 75 (node with two children) ===\n";
    tree.deleteNode(75);
    tree.inOrder();

    return 0;
}