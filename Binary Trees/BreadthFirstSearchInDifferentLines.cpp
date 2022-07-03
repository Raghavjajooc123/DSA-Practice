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

int main() {
	// Breadth First search displaying in different lines
	node* root = buildTree();
// 	printTree(root);
// 	cout<<endl;
	BreadthFirstSearch(root);
	cout<<endl;
	return 0;
}
