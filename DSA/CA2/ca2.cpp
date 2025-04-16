#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = right = nullptr;
    }
};

node* insert(node* root, int val) {
    if (!root) return new node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

node* findMin(node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

node* deletenode(node
    *root, int key) {
    if (!root) return nullptr;

    if (key < root->data) {
        root->left = deletenode(root->left, key);
    } else if (key > root->data) {
        root->right = deletenode(root->right, key);
    } else {
        if (!root->left) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        node* successor = findMin(root->right);
        root->data = successor->data;
        root->right = deletenode(root->right, successor->data);
    }
    return root;
}

void display(node* root) {
    if (!root) return;
    display(root->left);
    cout << root->data << " ";
    display(root->right);
}

int main() {
    node* root = nullptr;
    int values[] = {45, 25, 65, 15, 35, 55, 75};

    for (int val : values)
        root = insert(root, val);

    cout << "\nafter insertion of all elements:\n";
    display(root);
    cout << "\n";

    root = deletenode(root, 25);

    cout << "\nafter deleting 25:\n";
    display(root);
    cout << "\n";

    return 0;
}
