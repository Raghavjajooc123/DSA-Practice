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

void printAtLevelK(node* root, int k){
    if(root == NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printAtLevelK(root->left, k-1);
    printAtLevelK(root->right, k-1);
    return;
}

int printAtDistanceK(node* root, node* target, int k){
   if(root == NULL){
       return -1;
   } 
   if(root == target){
       printAtLevelK(target, k);
       return 0;
   }
   int DL = printAtDistanceK(root->left, target, k);
   if(DL!=-1){
       if(DL+1 == k){
           cout<<root->data<<" ";
       }
       else{
           printAtLevelK(root->right, k-2-DL);
       }
       return 1+DL;
   }
   int DR = printAtDistanceK(root->right, target, k);
   if(DR!=-1){
       if(DR+1 == k){
           cout<<root->data<<" ";
       }
       else{
           printAtLevelK(root->left, k-DR-2);
       }
       return 1+DR;
    }
    return -1;
}

int main(){
	//building tree 
	node* root = buildTree();
	bfs(root);
	int k;
	cin>>k;
	node* target = root->left->left;
	printAtDistanceK(root, target, k);
	return 0;
}
