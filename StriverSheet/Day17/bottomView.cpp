void bottomViewHelper(Node* root, map<int, pair<int, int>>& mp, int level, int vLevel){
        if(root == NULL) return;
        if(vLevel >= mp[level].second){
            mp[level] = {root->data, vLevel};
        }
        bottomViewHelper(root->left, mp, level-1, vLevel+1);
        bottomViewHelper(root->right, mp, level+1, vLevel+1);
        return;
    }
    vector <int> bottomView(Node *root) {
        map<int, pair<int, int>> mp;
        bottomViewHelper(root, mp, 0, 0);
        vector<int> ans;
        for(auto x:mp){
            ans.push_back(x.second.first);
        }
        return ans;
    }
