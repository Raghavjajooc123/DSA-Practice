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

node* bulidTreeFromArray(int* arr, int s, int e){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    node* root = new node(arr[mid]);
    root->left = bulidTreeFromArray(arr, s, mid-1);
    root->right = bulidTreeFromArray(arr, mid+1, e);
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
	//Tree from array
	int n;
	cin>>n;
	int arr[1000];
	for(int i=0; i<n; i++){
	    cin>>arr[i];
	}
	node* root = bulidTreeFromArray(arr, 0, n-1);
	bfs(root);
	return 0;
}
