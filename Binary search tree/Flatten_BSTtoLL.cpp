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

class Pair{
    public:
    node* head;
    node* tail;
    Pair(){
        head = NULL;
        tail = NULL;
    }
    Pair(node* h, node* t){
        head = h;
        tail = t;
    }
};

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

Pair BSTtoLL(node* root){
    Pair p;
    //base case
    if(root == NULL){
        p.head = p.tail = NULL;
        return p;
    }
    Pair leftans = BSTtoLL(root->left);
    Pair rightans = BSTtoLL(root->right);
    if((leftans.head == NULL) && (rightans.head == NULL)){
        p.head = p.tail = root;
    }
    else if((leftans.head != NULL) && (rightans.head == NULL)){
        leftans.tail->right = root;
        p.head = leftans.head;
        p.tail = root;
    }
    else if((leftans.head == NULL) && (rightans.head != NULL)){
        root->right = rightans.head;
        p.head = root;
        p.tail = rightans.tail;
    }
    else{
        root->right = rightans.head;
        leftans.tail->right = root;
        p.head = leftans.head;
        p.tail = rightans.tail;
    }
    return p;
}

void printLL(node* root){
    while(root!= NULL){
        cout<<root->data<<" --> ";
        root = root->right;
    }
    cout<<endl;
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
	cout<<endl;
	Pair ans = BSTtoLL(root);
	printLL(ans.head);
	return 0;
}
