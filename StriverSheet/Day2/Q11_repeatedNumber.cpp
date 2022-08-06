vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> ans;
    int n = A.size();
    int xorAll = 0;
    int xorArr = 0;
    for(int i=0; i<n; i++){
        xorAll = xorAll^A[i];
        xorAll = xorAll^(i+1);
        xorArr = xorArr^A[i];
    }
    //now we have A^B = xorAll
    xorAll = xorAll & ~(xorAll - 1); // finding the rightmost set bit
    int buk1 = 0;
    int buk2 = 0;
    for(int i=0; i<n; i++){
        if(A[i] & xorAll){
            buk1 = buk1 ^ A[i];
        }
        else{
            buk2 = buk2 ^ A[i];
        }
    }
    for(int i=1; i<=n; i++){
        if(i & xorAll){
            buk1 = buk1 ^ i;
        }
        else{
            buk2 = buk2 ^ i;
        }
    }
    
    ans.push_back(buk2);
    ans.push_back(buk1);
    
    //brute force
    // int n = A.size();
    // vector<int> countArr(n+1, 0);
    // for(int i=0; i<n; i++){
    //     countArr[A[i]]++;
    // }
    // int miss, twice;
    // for(int i=1; i<=n; i++){
    //     if(countArr[i] == 0){
    //         miss = i;
    //     }
    //     if(countArr[i] == 2){
    //         twice = i;
    //     }
    // }
    // ans.push_back(twice);
    // ans.push_back(miss);
    
    return ans;
}
