class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> present;
        int maxlen = 0;
        int l = 0;
        for(int r = 0; r<s.length(); r++){
            if(present.find(s[r])!=present.end()){
                while(s[l]!=s[r]){
                    present.erase(s[l]);
                    l++;
                }
                present.erase(s[l]);
                l++;
                present.insert(s[r]);
            }
            else{
                present.insert(s[r]);
                maxlen = max(maxlen, r-l+1);
            }
        }
        return maxlen;
    }
};
