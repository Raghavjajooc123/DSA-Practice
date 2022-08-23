class Solution {
public:
    void allSubsets(vector<int>& nums, int idx, vector<vector<int>> &ans, vector<int>& curr){
        ans.push_back(curr);
        for(int i=idx; i<nums.size(); i++){
            if(i!=idx && nums[i]==nums[i-1]) continue;
            curr.push_back(nums[i]);
            allSubsets(nums, i+1, ans, curr);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        allSubsets(nums, 0, ans, curr);
        return ans;
    }
};
