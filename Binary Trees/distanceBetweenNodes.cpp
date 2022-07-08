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

node* lowestCommonAncestor(node* root, int a, int b){
    if(root == NULL){
        return NULL;
    }
    if(root->data == a || root->data == b){
        return root;
    }
    node* LeftAns = lowestCommonAncestor(root->left, a, b);
    node* RightAns = lowestCommonAncestor(root->right, a, b);
    if(LeftAns && RightAns){
        return root;
    }
    else if(LeftAns){
        return LeftAns;
    }
    return RightAns;
}

int distanceBetween(node* root, int x, int level){
    if(root == NULL){
        return -1;
    }
    if(root->data == x){
        return level;
    }
    int leftans = distanceBetween(root->left, x, level+1);
    if(leftans!=-1){
        return leftans;
    }
    return distanceBetween(root->right, x, level+1);
}

int distanceBetweenNodes(node* root, int a, int b){
    node* LCA = lowestCommonAncestor(root, a, b);
    int d1 = distanceBetween(LCA, a, 0);
    int d2 = distanceBetween(LCA, b, 0);
    return d1+d2;
}

int main() {
	// Distance between two nodes in a tree
	node* root = buildTree();
	BreadthFirstSearch(root);
	cout<<endl;
	int ans = distanceBetweenNodes(root, -25, 1);
	cout<<ans<<endl;
	return 0;
}
