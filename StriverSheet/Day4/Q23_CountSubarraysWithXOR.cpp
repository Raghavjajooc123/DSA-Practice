int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int count = 0;
    
    //using hashing
    map<int, int> xorTable;
    int X = 0;
    for(int i=0; i<n; i++){
        X = X^A[i];
        if(X==B){
            count++;
        }
        if(xorTable.find(X^B) != xorTable.end()){
            count+=xorTable[X^B];
        }
        xorTable[X]++;
    }
    
    //commulative array approach
    // for(int i=1; i<n; i++){
    //     A[i] = A[i]^A[i-1];
    // }
    // for(int i=0; i<n; i++){
    //     for(int j=i; j<n; j++){
    //         if(i==0){
    //             if(A[j] == B){
    //                 count++;
    //             }
    //         }
    //         else{
    //             if(A[j]^A[i-1] == B){
    //                 count++;
    //             }   
    //         }
    //     }
    // }
    
    //brute force
    // for(int i=0; i<n; i++){
    //     for(int j=i; j<n; j++){
    //         int currxor = 0;
    //         for(int k=i; j<=j; k++){
    //             currxor = currxor^A[i];
    //         }
    //         if(currxor == B){
    //             count++;
    //         }
    //     }
    // }
    return count;
}
