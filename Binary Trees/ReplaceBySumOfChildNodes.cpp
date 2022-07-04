#include <iostream>
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

int SumOfChild(node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL  && root->right == NULL){
        return root->data;
    }
    int temp = root->data;
    root->data = SumOfChild(root->left) + SumOfChild(root->right);
    return root->data + temp;
}

int main() {
	//Replace by sum of child nodes
	node* root = bulidTree();
	printTree(root);
	cout<<endl;
	SumOfChild(root);
	printTree(root);
	return 0;
}
