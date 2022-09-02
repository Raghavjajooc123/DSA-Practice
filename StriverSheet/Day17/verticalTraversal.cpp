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
    void addValue(map<int, vector<pair<int, int>>>& mp, int x, TreeNode* root, int y){
        for(int i=0; i<mp[x].size(); i++){
            if(mp[x][i].second == y){
                if(mp[x][i].first > root->val){
                    mp[x].insert(mp[x].begin()+i, {root->val, y});
                    return;
                }
            }
            if(mp[x][i].second > y){
                mp[x].insert(mp[x].begin()+i, {root->val, y});
                return;
            }
        }
        mp[x].push_back({root->val, y});
    }
    void verticalHelper(TreeNode* root, map<int, vector<pair<int, int>>>& mp, int x, int y){
        if(root == NULL) return;
        addValue(mp, x, root, y);
        verticalHelper(root->left, mp, x-1, y+1);
        verticalHelper(root->right, mp, x+1, y+1);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;
        verticalHelper(root, mp, 0, 0);
        vector<vector<int>> ans;
        for(auto x:mp){
            vector<int> temp;
            for(auto a:x.second){
                temp.push_back(a.first);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
