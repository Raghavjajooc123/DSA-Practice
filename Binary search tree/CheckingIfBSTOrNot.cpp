#include <iostream>
#include <climits>
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

void BFS(node* root){
    if(root == NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* f = q.front();
        if(f == NULL){
            q.pop();
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<" ";
            q.pop();
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}

bool isBST(node* root, int case_max, int case_min){
    if(root == NULL){
        return true;
    }
    if(root->data <= case_max && root->data >= case_min && isBST(root->left, root->data, case_min) && isBST(root->right, case_max, root->data)){
        return true;
    }
    return false;
}

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

int main() {
	// Binary Search Tree Building
	node* root = buildTree();
	BFS(root);
	printInOrder(root);
	cout<<endl;
	cout<<isBST(root, INT_MAX, INT_MIN)<<endl;
}
