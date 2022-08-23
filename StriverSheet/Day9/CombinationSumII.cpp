class Solution {
public:
    void sumToTraget(vector<int>& A, int target, vector<vector<int>>& ans, vector<int>& curr, int sum, int idx)
    {
        if(sum == target){
            ans.push_back(curr);
            return;
        }
        if(sum>target){
            return;
        }
        
        for(int i=idx; i<A.size(); i++){
            if(i!=idx && A[i]==A[i-1]) continue;
            curr.push_back(A[i]);
            sumToTraget(A, target, ans, curr, sum+A[i], i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        sumToTraget(candidates, target, ans, curr, 0, 0);
        return ans;
    }
};
