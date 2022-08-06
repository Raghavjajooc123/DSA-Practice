class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        
        if(n<0){
            if(n == INT_MIN){
                n = n+1;
                return (1/x)*myPow((1/x) , -n);
            }
            else{
                return myPow((1/x), -n);
            }
        }
        
        if(n%2 == 0){
            return pow(x*x, n/2);
        }
        
        else{
            return x*pow(x*x, n/2);
        }
        
        
        //brute force
        // if(n==0){
        //     return 1;
        // }
        // if(n<0){
        //     if(n == INT_MIN){
        //         n = n+1;
        //         return (1/x)*myPow((1/x) , -n);
        //     }
        //     else{
        //         return myPow((1/x), -n);
        //     }
        // }
        // return x*myPow(x, n-1);
    }
};
