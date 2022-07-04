#include <iostream>
#include <cstdlib>
using namespace std;
class node{
    public:
        int data;
        node* left;
        node* right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
class Pair{
    public:
    bool isBalanced;
    int height;
};

node* bulidTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node* root = new node(d);
    root->left = bulidTree();
    root->right = bulidTree();
    return root;
}

void printTree(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
    return;
}

Pair heightBalanced(node* root){
    Pair p;
    if(root==NULL){
        p.isBalanced = true;
        p.height = 0;
        return p;
    }
    Pair left = heightBalanced(root->left);
    Pair right = heightBalanced(root->right);
    if(abs(left.height-right.height)<=1 && left.isBalanced && right.isBalanced){
        p.isBalanced = true;
    }
    else{
        p.isBalanced = false;
    }
    p.height = max(left.height, right.height)+1;
    return p;
}

int main() {
	//
	node* root = bulidTree();
	printTree(root);
	cout<<endl;
	Pair ans = heightBalanced(root);
	cout<<ans.isBalanced<<endl;
	cout<<ans.height<<endl;
	return 0;
}
