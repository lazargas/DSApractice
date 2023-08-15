#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int d){
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Tree {
public:
    Node* root;
    Node* CreateNode(int data) {
       Node* newNode = new Node(data);
       return newNode;
    }

    Node* insertNode(int index, vector<int> &data) {
        if (index < data.size() && data[index] != -1) {
            Node* node = CreateNode(data[index]);
            node->left = insertNode(2 * index + 1, data);
            node->right = insertNode(2 * index + 2, data);
            return node;
        }
        return nullptr;
    }

    void inorder(Node* root) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> data;

    for (int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        data.push_back(temp);
    }

    Tree tree;
    tree.root = tree.insertNode(0, data);
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}
