/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A, int B) {
    if(A == NULL) return {};
    if(A->val == B) return {A->val};
    vector<int> leftA = solve(A->left, B);
    vector<int> rightA = solve(A->right, B);
    if(leftA.size()){
        leftA.insert(leftA.begin(), A->val);
        return leftA;
    }
    if (rightA.size()){
        rightA.insert(rightA.begin(), A->val);
        return rightA;
    }
    return {};
}
