#include <iostream>
#include <queue>
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

node* buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
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

int depthTree(node* root){
    if(root==NULL){
        return 0;
    }
    int max_depth = max(depthTree(root->left), depthTree(root->right));
    return max_depth+1;
}

int diameterTree(node* root){
    if(root == NULL){
        return 0;
    }
    int op1 = diameterTree(root->left);
    int op2 = diameterTree(root->right);
    int op3 = 1+depthTree(root->left)+depthTree(root->right);
    return max(op1, max(op2,op3));
}

int main() {
	// Diameter of tree
	node* root = buildTree();
	printTree(root);
	cout<<endl;
	BreadthFirstSearch(root);
	int dia = diameterTree(root);
	cout<<dia<<endl;
	return 0;
}
