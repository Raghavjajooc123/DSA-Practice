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
    void reverse(vector<int>& v){
        for(int i=0; i<v.size()/2; i++){
            swap(v[i], v[v.size()-i-1]);
        }
        return;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        bool flag = 0;
        vector<int> curr;
        while(!q.empty()){
            TreeNode* temp = q.front();
            if(temp!=NULL) curr.push_back(temp->val);
            q.pop();
            
            if(temp==NULL){
                if(flag) reverse(curr);
                ans.push_back(curr);
                curr.clear();
                flag = flag^1;
                if(q.empty()) break;
                q.push(NULL);
            }
            else if(temp!=NULL){
                if(temp->left != NULL) q.push(temp->left); 
                if(temp->right != NULL) q.push(temp->right); 
            }
        }
        return ans;
    }
};
