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
    pair<int, int> diameterHelper(TreeNode* root){
        if(root == NULL) return {0,0};
        
        pair<int, int> leftA = diameterHelper(root->left);
        pair<int, int> rightA = diameterHelper(root->right);
        int currdia = leftA.second + rightA.second;
        return {max(currdia, max(leftA.first, rightA.first)) ,max(leftA.second, rightA.second)+1};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        //pair of max diameter, max height
        pair<int, int> ans = diameterHelper(root);
        return ans.first;
    }
};
