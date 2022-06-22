#include <iostream>
using namespace std;

class node{
    public:
    node* left;
    int data;
    node* right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* makeTree(){
    int d;
    cin>>d;
    if(d == -1){
        return NULL;
    }
    node* root = new node(d);
    root->left = makeTree();
    root->right = makeTree();
    return root;
}

void printTree(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}

void printTreeInOrder(node* root){
    if(root == NULL){
        return;
    }
    printTreeInOrder(root->left);
    cout<<root->data<<" ";
    printTreeInOrder(root->right);
}

void printTreePostOrder(node* root){
    if(root == NULL){
        return;
    }
    printTreePostOrder(root->left);
    printTreePostOrder(root->right);
    cout<<root->data<<" ";
}

int main() {
	// Binary Trees
	node* root = makeTree();
	printTree(root);
	cout<<endl;
	printTreeInOrder(root);
	cout<<endl;
	printTreePostOrder(root);
	return 0;
}

// i/p = 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
// o/p = 8 10 1 6 9 7 3 14 13 
//       1 10 9 6 7 8 3 13 14 
//       1 9 7 6 10 13 14 3 8 
