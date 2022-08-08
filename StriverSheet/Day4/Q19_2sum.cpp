class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //doing by map
        map<int, int> num;
        for(int i=0; i<nums.size(); i++){
            if(num.find(target - nums[i]) != num.end()){
                vector<int> ans = {i ,num[target - nums[i]]};
                return ans;
            }
            num[nums[i]] = i;
        }
        
        vector<int> ans = {0,0};
        return ans;
        
        //brute force
        // int i, j;
        // for(i=0; i<nums.size(); i++){
        //     for(j=i+1; j<nums.size(); j++){
        //         if(nums[i]+nums[j] == target){
        //             vector<int> ans = {i, j};
        //             return ans;
        //         }
        //     }
        // }
        // vector<int> ans = {i, j};
        // return ans;
    }
};
