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
    int branchSum;
    int maxSum;
    Pair(){
        branchSum = 0;
        maxSum = 0;
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

void BreadthFirstSearch(node* root){
    if(root == NULL){
        return;
    }
    queue<node*> Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
        node* f = Q.front();
        if(f==NULL){
            Q.pop();
            cout<<endl;
            if(!Q.empty()){
                Q.push(NULL);
            }
        }
        else{
            cout<<f->data<<" ";
            Q.pop();
            if(f->left){
                Q.push(f->left);
            }
            if(f->right){
                Q.push(f->right);
            }
        }
    }
    return;
}

Pair maxSumInTree(node* root){
    if(root == NULL){
        Pair p;
        return p;
    }
    Pair leftSum = maxSumInTree(root->left);
    Pair rightSum = maxSumInTree(root->right);
    int LS = leftSum.branchSum;
    int RS = rightSum.branchSum;
    int maxbranchSum = max(root->data, max(root->data+LS, max(root->data+RS, 0)));
    int maxSum1 = max(leftSum.maxSum, max(rightSum.maxSum, max(root->data+LS+RS, 0)));
    Pair p;
    p.maxSum = maxSum1;
    p.branchSum = maxbranchSum;
    return p;
}

int main() {
	// Max Sum in a tree
	node* root = buildTree();
	BreadthFirstSearch(root);
	cout<<endl;
	Pair ans = maxSumInTree(root);
	cout<<ans.maxSum<<endl;
	return 0;
}
