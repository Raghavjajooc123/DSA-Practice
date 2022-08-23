void sumOfSubset(vector<int> &num ,int n, int sum, vector <int> &ans){
    if(n == num.size()){
        ans.push_back(sum);
        return;
    }
    
    //if we choose the element
    sumOfSubset(num, n+1, sum+num[n], ans);
    sumOfSubset(num, n+1, sum, ans);
    return;
}
vector<int> subsetSum(vector<int> &num)
{
    vector <int> ans;
    sumOfSubset(num, 0, 0, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
