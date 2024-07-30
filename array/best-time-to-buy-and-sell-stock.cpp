//best-time-to-buy-and-sell-stock

/*You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0. */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int valley = INT_MAX;
        // int ans = 0;
        // for(int i = 0;i<prices.size();i++){
        //     if(prices[i] < valley){
        //         valley = prices[i];
        //     }else if(prices[i]-valley > ans){
        //         ans = prices[i]-valley;
        //     }
        // }
        // return ans;

        //...GREEDY APPROACH
        int profit = 0;
        int maxProfit = 0;
        int maxToTail = 0;
        for(int i= prices.size()-1;i>=0;i--){
            maxToTail = max(maxToTail, prices[i]);
            profit = max(maxToTail-prices[i],0);
            maxProfit = max(maxProfit,profit);
        }
        return maxProfit;

    }
};
