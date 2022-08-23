class Solution {
public:
    void targetSum(vector<int> &A, int target, int sum, int idx, vector<int> sol, vector<vector<int>> &ans)
    {
        if(sum == target){
            ans.push_back(sol);
            return;
        }
        if(sum>target){
            return;
        }
        
        for(int i=idx; i<A.size(); i++){
            sol.push_back(A[i]);
            targetSum(A, target, sum+A[i], i, sol, ans);
            sol.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sol;
        sort(candidates.begin(), candidates.end());
        targetSum(candidates, target, 0, 0, sol, ans);
        return ans;
    }
};
