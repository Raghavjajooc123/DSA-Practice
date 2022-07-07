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

void bfs(node* root){
    if(root == NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            q.pop();
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<" ";
            q.pop();
            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);
        }
    }
    return;
}

node* lowestCommonAncestor(node* root, int a, int b){
    if(root == NULL){
        return NULL;
    }
    if(root->data == a || root->data == b){
        return root;
    }
    node* leftAns = lowestCommonAncestor(root->left, a, b); 
    node* rightAns = lowestCommonAncestor(root->right, a, b);
    if(leftAns && rightAns){
        return root;
    }
    else if(leftAns){
        return leftAns;
    }
    return rightAns;
}

int main(){
	//lowest Common Ancestor
	node* root = buildTree();
	bfs(root);
	cout<<"LCA of 9 and 10 is "<<lowestCommonAncestor(root, 9, 10)->data<<endl;
	cout<<"LCA of 4 and 11 is "<<lowestCommonAncestor(root, 4, 11)->data<<endl;
	cout<<"LCA of 2 and 3 is "<<lowestCommonAncestor(root, 2, 3)->data<<endl;
	return 0;
}

// INPUT:-
// 1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
