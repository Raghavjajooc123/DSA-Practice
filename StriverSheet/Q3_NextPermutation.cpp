class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx1 = -1;
        for(int i=n-1; i>0; i--){
            if(nums[i-1] < nums[i]){
                idx1 = i-1;
                break;
            }
        }
        if(idx1 == -1){
            //reverse the array
            for(int i=0; i<n/2; i++){
                swap(nums[i], nums[n-i-1]);
            }
            return;
        }
        
        for(int j = n-1; j>idx1; j--){
            if(nums[j] > nums[idx1]){
                swap(nums[j],nums[idx1]);
                break;
            }
        }
        
        idx1++;
        int mid = (idx1+n)/2;
        for(int i = idx1; i<mid; i++){
            swap(nums[i], nums[n-1-(i-idx1)]);
        }
        
        return;
        
    }
};
