class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        bool is_negative = 0;
        int int_min = (1<<32-1);
        int int_max = -(int_min+1);
        long int ans = 0;
        while(s[i]!='\0'){
            if(s[i]==' '){
                i=i+1;
                continue;
            }
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || s[i]=='.'){
                break;
            }
            if(s[i]=='+' || s[i]=='-'){
                is_negative = (s[i]=='-');
                i=i+1;
                while(s[i]>='0' && s[i]<='9'){
                    ans = ans*10 + (s[i]-'0');
                    i=i+1;
                    if(ans>=int_max){
                        if(ans == int_max && is_negative){
                            return int_min+1;
                        }
                        ans = int_max;
                        break;
                    }
                }
                break;
            }
            if(s[i]>='0' && s[i]<='9'){
                while(s[i]>='0' && s[i]<='9'){
                    ans = ans*10 + (s[i]-'0');
                    i=i+1;
                    if(ans>=int_max){
                        ans = int_max;
                        break;
                    }
                }
                break;
            }
        }
        if(is_negative){
            if(ans==int_max){
                ans = int_min;
            }
            else{
                ans = -ans;
            }
        }
        return ans;
    }
};
