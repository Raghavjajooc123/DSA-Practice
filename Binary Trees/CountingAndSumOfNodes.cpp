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

int countNodes(node* root){
    if(root == NULL){
        return 0;
    }
    return (countNodes(root->left)+countNodes(root->right)+1);
}

int SumNodes(node* root){
    if(root == NULL){
        return 0;
    }
    return (SumNodes(root->left)+SumNodes(root->right)+root->data);
}

int main() {
	// Breadth First search
	node* root = buildTree();
	printTree(root);
	cout<<endl;
	BreadthFirstSearch(root);
	int n = countNodes(root);
	cout<<n<<endl;
	int sum = SumNodes(root);
	cout<<sum<<endl;
	return 0;
}
