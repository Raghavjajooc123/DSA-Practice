#include <iostream>
#include <vector>
#include <string>
#include <map>
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

map<int, vector<int>> v;

void vertical_order_print(node* root, int dis){
    if(root == NULL){
        return;
    }
    v[dis].push_back(root->data);
    vertical_order_print(root->left, dis-1);
    vertical_order_print(root->right, dis+1);
    return;
}

int main() {
	// vertical print of a tree
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	root->left->right->right = new node(8);
	root->right->right->right = new node(9);
	
	vertical_order_print(root, 0);
	
	for(auto list:v){
	    for(int element:list.second){
	        cout<<element<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
