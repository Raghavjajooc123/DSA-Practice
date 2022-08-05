class Solution {
public:
    vector<int> PascalHelper(vector<vector<int>> pascal, int count){
        vector<int> ans;
        ans.push_back(1);
        for(int i=1; i<count; i++){
            ans.push_back(pascal[count-1][i-1] + pascal[count-1][i]);
        }
        ans.push_back(1);
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        pascal.push_back({1});
        for(int i=1; i<numRows; i++){
            pascal.push_back(PascalHelper(pascal, i));
        }
        return pascal;
    }
};
