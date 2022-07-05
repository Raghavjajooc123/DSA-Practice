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

void printRightView(node* root, int & max_level, int curr_level){
    if(root == NULL){
        return;
    }
    if(curr_level>max_level){
        cout<<root->data<<" ";
        max_level = curr_level;
    }
    printRightView(root->right, max_level, curr_level+1);
    printRightView(root->left, max_level, curr_level+1);
    return;
}

int main(){
	//building tree 
	node* root = buildTree();
	bfs(root);
	int maxlevel = -1;
	printRightView(root, maxlevel, 0);
	return 0;
}
