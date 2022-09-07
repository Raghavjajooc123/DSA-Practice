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
    bool isSame(TreeNode* a, TreeNode* b){
        if(a==NULL && b==NULL) return true;
        else if((a==NULL && b!=NULL) || (a!=NULL && b==NULL)) return false;
        return ((a->val == b->val) && isSame(a->left, b->right) && isSame(a->right, b->left));
    }
    bool isSymmetric(TreeNode* root) {
        return isSame(root->left, root->right);
    }
};
