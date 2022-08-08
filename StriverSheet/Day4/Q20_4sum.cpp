class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector <int>> ans;
        if(n==0){
            return ans;
        }
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int s = j+1;
                int e = n-1;
                long t = long(target) - long(nums[i] + nums[j]);
                while(s<e){
                    int x = nums[s] + nums[e];
                    if(x<t){
                        s++;
                    }
                    else if(x>t){
                        e--;
                    }
                    else{
                        vector<int> quad(4,0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[s];
                        quad[3] = nums[e];
                        ans.push_back(quad);
                        while(s<e && nums[s] == quad[2]) s++;
                        while(s<e && nums[e] == quad[3]) e--;
                    }
                }  
                while(j+1 < n-1 && nums[j+1] == nums[j]){
                    j++;
                }   
            }
            while(i+1 < n-1 && nums[i+1] == nums[i]){
                i++;
            }
        }
        return ans;
    }
};
