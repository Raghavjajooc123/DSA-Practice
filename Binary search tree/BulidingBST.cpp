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
	BFS(root);
	printInOrder(root);
	return 0;
}
