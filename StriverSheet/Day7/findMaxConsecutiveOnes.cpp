class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxsize = 0;
        int currsize = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                maxsize = max(maxsize, currsize);
                currsize = 0;
            }
            else{
                currsize++;
            }
        }
        maxsize = max(maxsize, currsize);
        return maxsize;
    }
};
