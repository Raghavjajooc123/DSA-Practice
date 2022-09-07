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
    // approach-1 The hard one
    // pair<int, int> maxPathHelper(TreeNode* root){
    //     if(root == NULL) return{0, 0};
    //     if(root->left == NULL && root->right == NULL) return{root->val, root->val};
    //     pair<int, int> lans, rans;
    //     if(root->left != NULL) lans = maxPathHelper(root->left);
    //     if(root->right != NULL) rans = maxPathHelper(root->right);
    //     int maxbsum = 0, maxpathsum = 0;
    //     if(root->left != NULL && root->right != NULL){
    //         maxbsum = root->val + max(lans.second, max(rans.second, 0));
    //         maxpathsum = max(root->val + lans.second + rans.second, max(lans.first, rans.first));
    //     }
    //     else if(root->left == NULL && root->right != NULL){
    //         maxbsum = root->val + max(rans.second, 0);
    //         maxpathsum = max(root->val + rans.second, rans.first);
    //     }
    //     else if(root->left != NULL && root->right == NULL){
    //         maxbsum = root->val + max(lans.second, 0);
    //         maxpathsum = max(root->val + lans.second, lans.first);
    //     }
    //     return {maxpathsum, maxbsum};
    // }
    
    int maxPathHelper(TreeNode* root, int& maxi){
        if(root == NULL) return 0;
        int leftans = max(0, maxPathHelper(root->left, maxi));
        int rightans = max(0, maxPathHelper(root->right, maxi));
        maxi = max(maxi, leftans+rightans+root->val);
        return root->val + max(leftans, rightans);
    }
    int maxPathSum(TreeNode* root) {
        // int maxi = INT_MIN;
        // int ans = maxPathHelper(root, maxi);
        // return maxi;
        pair<int, int> ans = maxPathHelper(root);
        return ans.first;
    }
};
