class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int temp = x;
        long long int pallindrome = 0;
        while(temp){
            pallindrome = pallindrome*10 + temp%10;
            temp = temp/10;
        }
        cout<<pallindrome<<endl;
        if(pallindrome == x){
            return true;
        }
        return false;
    }
};
