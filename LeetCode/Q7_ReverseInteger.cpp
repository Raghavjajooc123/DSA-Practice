class Solution {
public:
    int reverse(int x) {
        long int ans = 0;
        int int_max = 2147483647;
        int int_min = -2147483648;
        bool negative_no = (x<0);
        if(negative_no){
            if(x == int_min){
                x=0;
            }
            x = -x;
        }
        while(x!=0){
            ans = ans*10+(x%10);
            x=x/10;
            if(ans > int_max){
                ans = 0;
                break;
            }
        }
        if(negative_no){
            ans = -ans;
        }
        return ans;
    }
};
