class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        //By Map
        // int maxSize = 0;
        // int maxEle;
        // unordered_map<int, int> count;
        // for(int i=0; i<n; i++){
        //     if(!count[nums[i]]){
        //         count[nums[i]] = 1;
        //         if(maxSize == 0){
        //             maxSize = 1;
        //             maxEle = nums[i];
        //         }
        //     }
        //     else{
        //         count[nums[i]]++;
        //         if(count[nums[i]] > maxSize){
        //             maxEle = nums[i];
        //             maxSize = count[nums[i]];
        //         }
        //     }
        // }
        // return maxEle;
        
        // Boyer-Moore Majority Vote Algorithm -- very good algo
        int majority = 0;
        int count = 0;
        for(int i=0; i<n; i++){
            if(count == 0){
                majority = nums[i];
            }
            
            if(nums[i] == majority){
                count++;
            }
            else{
                count--;
            }
        }
        return majority;
        
    }
};
