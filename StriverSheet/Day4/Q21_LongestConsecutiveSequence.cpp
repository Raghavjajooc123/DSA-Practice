class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        //by set
        set<int> hashSet;
        for(int i=0; i<n; i++){
            hashSet.insert(nums[i]);
        }
        int maxlen = 0;
        for(int i=0; i<n; i++){
            if(!hashSet.count(nums[i]-1)){
                int currlen = 1;
                int temp = i;
                while(hashSet.count(++nums[temp])){
                    currlen++;
                }
                maxlen = max (maxlen, currlen);
            }
        }
        return maxlen;
        
        //using map
        // map<int, int> l;
        // int ans = 0;
        // for(int i=0; i<n; i++){
        //     l[nums[i]]++;
        // }
        // int maxlen = 0;
        // for(int i=0; i<n; i++){
        //     int currlen = 0;
        //     int temp = i;
        //     if(l[nums[temp]]){
        //         if(l[nums[temp]-1] == 0){
        //             currlen = 1;
        //             while(l[++nums[temp]]!=0){
        //                 currlen++;
        //             }
        //             maxlen = max (maxlen, currlen);
        //         }
        //     }
        // }
        // return maxlen;
    }
};
