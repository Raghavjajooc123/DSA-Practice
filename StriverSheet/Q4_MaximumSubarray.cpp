class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        int ms = 0;
        int cs = 0;
        for(int i=0; i<n; i++){
            cs+=nums[i];
            if(cs<0){
                cs = 0;
            }
            if(cs>ms){
                ms=cs;
            }
        }
        if(ms == 0){
            int maxNum = INT_MIN;
            for(int i=0; i<n; i++){
                if(nums[i] > maxNum){
                    maxNum = nums[i];
                }
            }
            ms = maxNum;
        }
        return ms;
    }
};
