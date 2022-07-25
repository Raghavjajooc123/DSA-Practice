#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int maxProfit(int * wines, vector<vector<int>> & profit, int s, int e, int years, int curr_year){
    //base case
    if(s==e){
        return wines[s]*curr_year;
    }
    //finding value
    if(profit[s][e] != 0){
        return profit[s][e];
    }
    //rec case
    int op_s = wines[s]*curr_year + maxProfit(wines, profit, s+1, e, years, curr_year+1);
    int op_e = wines[e]*curr_year + maxProfit(wines, profit, s, e-1, years, curr_year+1);
    profit[s][e] = max(op_s, op_e);
    return profit[s][e];
}
int main() {
	// wines problem
	int n;
	cin>>n;
	int wines[100];
	for(int i=0; i<n; i++){
	    cin>>wines[i];
	}
	vector<vector<int>> profit( 100 , vector<int> (100, 0)); 
	cout<<maxProfit(wines, profit, 0, n-1, n, 1);
	return 0;
}
