class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
         // brute force
//         int maxprofit = 0;
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 if(prices[j]-prices[i] > maxprofit){
//                     maxprofit = prices[j]-prices[i];
//                 }
//             }
//         }
//         return maxprofit;
        
        int minSoFar = INT_MAX;
        int profitToday = 0;
        int maxP = 0;
        
        for(int i=0; i<n; i++){
            if(prices[i] < minSoFar){
                minSoFar = prices[i];
            }
            profitToday = prices[i] - minSoFar;
            if(profitToday > maxP){
                maxP = profitToday;
            }
        }
        return maxP;
    }
};
