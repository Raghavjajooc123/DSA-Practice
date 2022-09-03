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
    pair<bool, int> isBalHelper(TreeNode* root) {
        if(root == NULL) return {true, 0};
        pair<bool, int> leftA = isBalHelper(root->left);
        pair<bool, int> rightA = isBalHelper(root->right);
        if(leftA.first && rightA.first && (abs(leftA.second - rightA.second)<=1)){
            return {true, max(leftA.second, rightA.second)+1};
        }
        return{false, max(leftA.second, rightA.second)+1};
    }
    bool isBalanced(TreeNode* root) {
        pair<bool, int> ans = isBalHelper(root);
        return ans.first;
    }
};
