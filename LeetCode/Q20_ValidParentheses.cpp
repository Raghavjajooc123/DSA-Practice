class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int i=0;
        while(s[i]!='\0'){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                stk.push(s[i]);
            }
            else if(s[i]==')' || s[i]=='}' || s[i]==']'){
                if(stk.empty()){
                   return false; 
                }
                else if(s[i]==')'){
                    if(stk.top() == '('){
                        stk.pop();
                    }
                    else{
                        return false;
                    }
                }
                else if(s[i]=='}'){
                    if(stk.top() == '{'){
                        stk.pop();
                    }
                    else{
                        return false;
                    }
                }
                else if(s[i]==']'){
                    if(stk.top() == '['){
                        stk.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
            i++;
        }
        if(stk.empty()){
            return true;
        }
        return false;
    }
};
