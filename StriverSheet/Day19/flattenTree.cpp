/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<TreeNode*, TreeNode*> flattenHelper(TreeNode* root){
        if(root == NULL || root->left==NULL && root->right == NULL){
            return{root, root};
        }
        
        pair<TreeNode*, TreeNode*> lans, rans;
        if(root->left != NULL) lans = flattenHelper(root->left);
        if(root->right != NULL) rans = flattenHelper(root->right);
        
        TreeNode* tail;
        if(root->left != NULL && root->right != NULL){
            root->right = lans.first;
            lans.second->right = rans.first;
            tail = rans.second;
        }
        else if(root->left == NULL && root->right != NULL){
            root->right = rans.first;
            tail = rans.second;
        }
        else if(root->left != NULL && root->right == NULL){
            root->right = lans.first;
            tail = lans.second;
        }
        root->left = NULL;
        return {root, tail};
    }
    void flatten(TreeNode* root) {
        pair<TreeNode*, TreeNode*> ans = flattenHelper(root);
        return;
    }
};
