class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        //using moose voting algorithm
        int n = nums.size();
        int num1, num2, count1 = 0, count2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == num1) count1++;
            else if(nums[i] == num2) count2++;
            else if(count1 == 0){
                num1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0){
                num2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        count1=count2=0;
        for(int i=0; i<n; i++){
            if(nums[i] == num1){
                count1++;
            }
            if(nums[i] == num2){
                count2++;
            }
        }
        if(count1 > n/3){
            ans.push_back(num1);
        }
        if(count2 > n/3){
            ans.push_back(num2);
        }
        return ans;
        
        //brute force using map
        // unordered_map<int, int> count;
        // vector<int> ans;
        // int n = nums.size();
        // for(int i=0; i<n; i++){
        //     count[nums[i]]++;
        // }
        // for(auto x: count){
        //     if(x.second > n/3){
        //         ans.push_back(x.first);
        //     }
        // }
        // return ans;
    }
};
