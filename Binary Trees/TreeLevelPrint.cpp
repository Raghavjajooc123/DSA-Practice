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

int getHeight(node* root){
    //base case
    if(root == NULL){
        return 0;
    }
    
    //rec case
    return (max(getHeight(root->left), getHeight(root->right))+1);
}

void printKthLevel(node* root, int k){
    if(root == NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
    return;
}

void TreeLevelPrint(node* root){
    int height = getHeight(root);
    for(int i=1; i<=height; i++){
        printKthLevel(root, i);
        cout<<endl;
    }
}

int main() {
	// Binary Trees
	node* root = makeTree();
	printTree(root);
	cout<<endl;
	TreeLevelPrint(root);
    
    return 0;
}
