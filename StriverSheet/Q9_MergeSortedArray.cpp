class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0){
            return;
        }
        int i=m-1, j=n-1;
        int pos = m+n-1;
        while(pos>=0 && i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[pos] = nums1[i];
                i--;
                pos--;
            }
            else{
                nums1[pos] = nums2[j];
                j--;
                pos--;
            }
        }
        while(j>=0){
            nums1[pos] = nums2[j];
            j--;
            pos--;
        }
        return;
    }
};
