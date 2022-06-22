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

int main() {
	// Binary Trees
	node* root = makeTree();
	printTree(root);
	return 0;
}

// i/p = 2 3 -1 5 -1 -1 6 2 -1 -1 -1
// o/p = 2 3 5 6 2 
