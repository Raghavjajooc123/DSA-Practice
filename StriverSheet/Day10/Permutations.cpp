class Solution {
public:
    //approach using extra space for the map
    // void permutations(vector<int>& nums, vector<vector<int>> &ans, vector<int>& curr, map<int, bool>& visited, int count){
    //     if(count == nums.size()){
    //         ans.push_back(curr);
    //         return;
    //     }
    //     for(int i=0; i<nums.size(); i++){
    //         if(!visited[nums[i]]){
    //             visited[nums[i]] = 1;
    //             curr.push_back(nums[i]);
    //             permutations(nums, ans, curr, visited, count+1);
    //             curr.pop_back();
    //             visited[nums[i]] = 0;
    //         }
    //     }
    // }
    
    //approach using less space - using swapping
    void permutationsOptimised(vector<int>& nums, vector<vector<int>> &ans, vector<int>& curr, int idx){
        if(idx == nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=idx; i<nums.size(); i++){
            curr.push_back(nums[i]);
            swap(nums[idx], nums[i]);
            permutationsOptimised(nums, ans, curr, idx+1);
            swap(nums[idx], nums[i]);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        //swapping approach
        permutationsOptimised(nums, ans, curr, 0);
        
        //for map approach
        // sort(nums.begin(), nums.end());
        // map<int, bool> visited;
        // for(int i=0; i<n; i++){
        //     visited[nums[i]] = 0;
        // }
        // permutations(nums, ans, curr, visited, 0);
        return ans;
    }
};
