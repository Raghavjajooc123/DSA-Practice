#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {
    int n = arr.size();
    int maxlen = 0;
    
    //most optimized approach - using hashmap
    map<int, int> sums;
    int s = 0;
    sums[0] = -1;
    for(int i=0; i<n; i++){
        s += arr[i];
        if(sums.find(s) != sums.end()){
            maxlen = max(maxlen, i-sums[s]);
        }
        else{
            sums[s] = i;
        }
    }
    
    //comutative array
//     for(int i=1; i<n; i++){
//         arr[i] = arr[i-1]+arr[i]; 
//     }
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             if(i==0){
//                 if(arr[j] == 0){
//                     maxlen = max(maxlen, j+1);
//                 }
//             }
//             else{
//                 if((arr[j] - arr[i-1]) == 0){
//                     maxlen = max(maxlen, j-i+1);
//                 }
//             }
//         }
//     }
    
    //brute force
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             int currsum = 0;
//             int currlen = 0;
//             for(int k=i; k<=j; k++){
//                 currsum+=arr[k];
//                 currlen++;
//             }
//             if(currsum == 0){
//                 maxlen = max(maxlen, currlen);
//             }
//         }
//     }
    return maxlen;
}
