class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int mid = 0;
        int e = n-1;
        
        while(mid<=e){
            if(nums[mid] == 0){
                swap(nums[mid], nums[s]);
                s++;
                mid++;
            }
            else if(nums[mid] == 2){
                swap(nums[mid], nums[e]);
                e--;
            }
            else{
                mid++;
            }
        }
        
        //counting sort --- brute force
        // int cone, czero;
        // cone=czero=0;
        // for(int i=0; i<n; i++){
        //     if(nums[i] == 0){
        //         czero++;
        //     }
        //     else if(nums[i] == 1){
        //         cone++;
        //     }
        // }
        // int i=0;
        // for(; i<czero; i++){
        //     nums[i] = 0;
        // }
        // for(;i< czero+cone; i++){
        //     nums[i] = 1;
        // }
        // for(;i<n; i++){
        //     nums[i] = 2;
        // }
        // return;
        
        
    }
};
