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

node* bulidTreeFromPreAndInOrder(int* preOrder, int* inOrder, int s, int e){
    static int a = 0;
    if(s>e){
        return NULL;
    }
    node* root = new node(preOrder[a]);
    int pos = -1;
    for(pos=s; pos<=e; pos++){
        if(inOrder[pos] == preOrder[a]){
            break;
        }
    }
    a++;
    root->left = bulidTreeFromPreAndInOrder(preOrder, inOrder, s, pos-1);
    root->right = bulidTreeFromPreAndInOrder(preOrder, inOrder, pos+1, e);
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

int main() {
	//building tree from inorder and preorder traversal
	int n;
	cin>>n;
	int preOrder[1000];
	for(int i=0; i<n; i++){
	    cin>>preOrder[i];
	}
	int inOrder[1000];
	for(int i=0; i<n; i++){
	    cin>>inOrder[i];
	}
	node* root = bulidTreeFromPreAndInOrder(preOrder, inOrder, 0, n-1);
	bfs(root);
	return 0;
}
