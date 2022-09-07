class Solution
{
    void topHelper(Node *root, map<int, pair<int, int>>& mp, int x, int y){
        if(root == NULL) return;
        if(mp.find(x) == mp.end()) mp[x] = {root->data, y};
        else if(mp[x].second > y) mp[x] = {root->data, y};
        topHelper(root->left, mp, x-1, y+1);
        topHelper(root->right, mp, x+1, y+1);
        return;
    }
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int, pair<int, int>> mp;
        topHelper(root, mp, 0, 0);
        vector<int> ans;
        for(auto x:mp){
            ans.push_back(x.second.first);
        }
        return ans;
    }

};
