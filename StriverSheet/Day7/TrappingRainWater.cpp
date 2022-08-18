class Solution {
public:
    int trap(vector<int>& height) {
        //optimal approach
        int n = height.size();
        int water = 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int leftMax = 0, rightMax = 0;
        for(int i=0; i<n; i++){
            leftMax = max(height[i], leftMax);
            rightMax = max(rightMax, height[n-i-1]);
            left[i] = leftMax;
            right[n-i-1] = rightMax;
        }
        for(int i=0; i<n; i++){
            int h = min(left[i], right[i]);
            water+=(h-height[i]);
        }
        return water;
        
        //brute force - calculating for each blocks left and right
        // int n = height.size();
        // int water = 0;
        // for(int i=0; i<n; i++){
        //     int left=0, right=0;
        //     for(int j=0; j<=i; j++){
        //         left = max(left, height[j]);
        //     }
        //     for(int j=i; j<n; j++){
        //         right = max(right, height[j]);
        //     }
        //     int h = min(left, right);
        //     water+=(h-height[i]);
        // }
        // return water;
    }
};
