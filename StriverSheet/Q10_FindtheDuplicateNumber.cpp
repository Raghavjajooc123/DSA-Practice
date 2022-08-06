class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        
        // BY COUNTING SORT
        int n = nums.size();
        int countSort[n];
        for(int i=0; i<n; i++){
            countSort[i] = 0;
        }
        for(int i=0; i<n; i++){
            countSort[nums[i]]++;
        }
        int ans = -1;
        for(int i=0; i<n; i++){
            if(countSort[i] > 1){
                ans = i;
            }
        }
        return ans;
    }
};
