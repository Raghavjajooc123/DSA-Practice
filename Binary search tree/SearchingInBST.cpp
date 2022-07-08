#include <iostream>
#include <queue>
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

void printInOrder(node* root){
    if(root == NULL){
        return;
    }
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
    return;
}

bool searchBST(node* root, int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(key<root->data){
        return searchBST(root->left, key);
    }
    return searchBST(root->right, key);
}

node* insertInBST(node* root, int d){
    if(root == NULL){
        return new node(d);
    }
    
    if(d<=root->data){
        root->left = insertInBST(root->left, d);
    }
    else{
        root->right = insertInBST(root->right, d);
    }
    return root;
}

node* buildBST(){
    int d;
    cin>>d;
    node* root = NULL;
    while(d!=-1){
        root = insertInBST(root, d);
        cin>>d;
    }
    return root;
}

int main() {
	// Binary Search Tree Building
	node* root = buildBST();
	printInOrder(root);
    cout<<searchBST(root, 9)<<endl;
	return 0;
}
