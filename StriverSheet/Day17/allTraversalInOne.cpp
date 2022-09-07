/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
#include <stack>
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    vector<int> preorder, postorder, inorder;
    stack<pair<BinaryTreeNode<int> *, int>> s;
    s.push({root, 1});
    while(!s.empty()){
        pair<BinaryTreeNode<int> *, int> temp = s.top();
        s.pop();
        if(temp.second == 1){
            preorder.push_back(temp.first->data);
            s.push({temp.first, temp.second+1});
            if(temp.first->left != NULL){
                s.push({temp.first->left, 1});
            }
        }
        else if(temp.second == 2){
            inorder.push_back(temp.first->data);
            s.push({temp.first, temp.second+1});
            if(temp.first->right != NULL){
                s.push({temp.first->right, 1});
            }
        }
        else{
            postorder.push_back(temp.first->data);
        }
    }
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    return ans;
}
