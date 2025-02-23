#include <iostream>
#include <cstring>
using namespace std;

class node {
public:
    node* right, * left;
    char key[100], mean[100];

    node() {
        right = NULL;
        left = NULL;
    }
};

class Tree {
public:
    node* root = NULL;

    node* create();
    void display(node* root);
    void insert(node*& root, node* temp);
    void update(node* root);
    node* deleteKeyword(node* root, char k[]);
    void displayAscending(node* root);
    void displayDescending(node* root);
    int maxComparisons(node* root);
    int calculateHeight(node* root);
};

node* Tree::create() {
    int ch;
    do {
        node* temp = new node;
        cout << "ENTER THE KEYWORD: " << endl;
        cin >> temp->key;
        cout << "ENTER THE MEANING: " << endl;
        cin >> temp->mean;
        temp->left = NULL;
        temp->right = NULL;
        insert(root, temp);
        cout << "DO YOU WANT TO CONTINUE: 1/0" << endl;
        cin >> ch;
    } while (ch != 0);
    return root;
}

void Tree::insert(node*& root, node* temp) {
    if (root == NULL) {
        root = temp;
    } else {
        if (strcmp(temp->key, root->key) < 0) {
            if (root->left == NULL)
                root->left = temp;
            else
                insert(root->left, temp);
        } else {
            if (root->right == NULL)
                root->right = temp;
            else
                insert(root->right, temp);
        }
    }
}

void Tree::display(node* root) {
    if (root == NULL)
        return;
    else {
        cout << "KEYWORD: " << root->key << endl;
        cout << "MEANING: " << root->mean << endl;
        display(root->left);
        display(root->right);
    }
}

void Tree::update(node* root) {
    char k[100], meaning[100];
    cout << "ENTER THE KEY TO BE UPDATED: " << endl;
    cin >> k;

    while (root != NULL) {
        if (strcmp(root->key, k) == 0) {  // Key found
            cout << "ENTER THE NEW MEANING: " << endl;
            cin >> meaning;
            strcpy(root->mean, meaning);
            cout << "MEANING UPDATED SUCCESSFULLY!" << endl;
            return;
        } else if (strcmp(root->key, k) > 0) {  // Search in the left subtree
            root = root->left;
        } else {  // Search in the right subtree
            root = root->right;
        }
    }
    // Key not found
    cout << "KEY DOES NOT EXIST!!!" << endl;
}


node* Tree::deleteKeyword(node* root, char k[]) {
    if (root == NULL) {
        cout << "KEY DOES NOT EXIST!!!" << endl;
        return NULL;
    }

    if (strcmp(k, root->key) < 0) {
        root->left = deleteKeyword(root->left, k);
    } else if (strcmp(k, root->key) > 0) {
        root->right = deleteKeyword(root->right, k);
    } else {
        // Node with one or no child
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor
        node* temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }

        // Replace root's data with inorder successor
        strcpy(root->key, temp->key);
        strcpy(root->mean, temp->mean);

        // Delete the inorder successor
        root->right = deleteKeyword(root->right, temp->key);
    }
    return root;
}

void Tree::displayAscending(node* root) {
    if (root == NULL)
        return;
    displayAscending(root->left);
    cout << root->key << ": " << root->mean << endl;
    displayAscending(root->right);
}

void Tree::displayDescending(node* root) {
    if (root == NULL)
        return;
    displayDescending(root->right);
    cout << root->key << ": " << root->mean << endl;
    displayDescending(root->left);
}

int Tree::calculateHeight(node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    return 1 + max(leftHeight, rightHeight);
}

int Tree::maxComparisons(node* root) {
    return calculateHeight(root);
}

int main() {
    Tree t;
    int choice;
    char keyword[100];

    do {
        cout << "\n1.CREATE A BINARY TREE\n2.DISPLAY BINARY TREE (Preorder)\n";
        cout << "3.UPDATE KEYWORD\n4.DELETE KEYWORD\n";
        cout << "5.DISPLAY IN ASCENDING ORDER\n6.DISPLAY IN DESCENDING ORDER\n";
        cout << "7.MAXIMUM COMPARISONS FOR SEARCH\n8.EXIT\n";
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
        case 1:
            t.create();
            break;
        case 2:
            t.display(t.root);
            break;
        case 3:
            t.update(t.root);
            break;
        case 4:
            cout << "ENTER THE KEYWORD TO DELETE: ";
            cin >> keyword;
            t.root = t.deleteKeyword(t.root, keyword);
            break;
        case 5:
            cout << "DICTIONARY IN ASCENDING ORDER:\n";
            t.displayAscending(t.root);
            break;
        case 6:
            cout << "DICTIONARY IN DESCENDING ORDER:\n";
            t.displayDescending(t.root);
            break;
        case 7:
            cout << "MAXIMUM COMPARISONS REQUIRED FOR SEARCH: " << t.maxComparisons(t.root) << endl;
            break;
        case 8:
            cout << "EXITING............:)" << endl;
            break;
        default:
            cout << "INVALID CHOICE!!!" << endl;
            break;
        }
    } while (choice != 8);

    return 0;
}
