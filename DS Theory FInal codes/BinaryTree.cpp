#include <iostream>
#include <vector>
using namespace std;

class Node{
    
    int data;
    Node* left;
    Node* right;
    
    Node(int d){
        data = d;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int>& preorder){
    idx++;

    if(preorder[idx] == -1){
        return NULL; // -1 means that the root has no child so we attach NULL with that node on child's place
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

void preOrder(Node* root){
    if (root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if (root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if (root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int tree_Height(Node* root){
    if (root == NULL){
        return 0;
    }

    int left_height = tree_Height(root->left);
    int right_height = tree_Height(root->right);

    return 1+max(left_height,right_height);
}

int NumNodes(Node* root){
    if (root == NULL){
        return 0;
    }

    int left_count = NumNodes(root->left);
    int right_count = NumNodes(root->right);

    return 1 + left_count + right_count;
}

int sumOfNodes(Node* root){
    if (root == NULL){
        return 0;
    }

    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);

    return leftSum + rightSum + root->data;
}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(preorder);

    cout << "Root data:" << root->data << endl;

    cout << "Pre order traversal:" << endl;
    preOrder(root);
    cout << endl;
    
    cout << "In order traversal:" << endl;
    inOrder(root);
    cout << endl;
    
    cout << "Post order traversal:" << endl;
    postOrder(root);
    cout << endl;

    cout << "Height of the tree: " << tree_Height(root) << endl;

    cout << "Total number of nodes in the tree: " << NumNodes(root) << endl;

    cout << "Sum of nodes of tree: " << sumOfNodes(root) << endl;

    return 0;
}