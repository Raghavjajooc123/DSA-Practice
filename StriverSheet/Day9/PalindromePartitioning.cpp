class Solution {
public:
    bool isPallindrome(string s, int st, int e){
        while(st<e){
            if(s[st] != s[e]){
                return false;
            }
            st++;
            e--;
        }
        return true;
    }
    void partitioning(string s, vector<string>& curr, vector<vector<string>>& ans, int idx){
        if(idx == s.length()){
            ans.push_back(curr);
            return;
        }
        for(int i=idx; i<s.length(); i++){
            if(isPallindrome(s, idx, i)){
                string temp = s.substr(idx, i-idx+1);
                curr.push_back(temp);
                partitioning(s, curr, ans, i+1);
                curr.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        partitioning(s, curr, ans, 0);
        return ans;
    }
};
