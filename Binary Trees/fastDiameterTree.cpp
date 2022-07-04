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

class Pair{
    public:
        int height;
        int diameter;
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

Pair fastDiameterTree(node* root){
    Pair p;
    if(root==NULL){
        p.height=p.diameter=0;
        return p;
    }
    Pair left = fastDiameterTree(root->left);
    Pair right = fastDiameterTree(root->right);
    p.height = max(left.height, right.height)+1;
    p.diameter = max(left.height+right.height+1, max(left.diameter, right.diameter));
    return p;
}


int main() {
	// Diameter of tree fast
	node* root = buildTree();
	printTree(root);
	cout<<endl;
	Pair ans = fastDiameterTree(root);
	cout<<ans.height<<endl;
	cout<<ans.diameter<<endl;
	return 0;
}
