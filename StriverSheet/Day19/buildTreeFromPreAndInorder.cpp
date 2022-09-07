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
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int sin, int ein, int spre, int epre){
        if(sin>ein || spre>epre) return NULL;
        int a = preorder[spre];
        int pivot;
        for(int i=sin; i<=ein; i++){
            if(inorder[i] == a){
                pivot = i;
                break;
            }
        }
        int numsLeft = pivot-sin;
        TreeNode* root = new TreeNode(a);
        root->left = buildTreeHelper(preorder, inorder, sin, pivot-1, spre+1, spre+numsLeft);
        root->right = buildTreeHelper(preorder, inorder, pivot+1, ein, spre+numsLeft+1, epre);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = 0;
        TreeNode* root = buildTreeHelper(preorder, inorder, 0, inorder.size()-1, 0, preorder.size()-1);
        return root;
    }
};
