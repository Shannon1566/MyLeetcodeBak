/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minCost=prices[0],profit=0;
        vector<int> dp(prices.size());
        dp[0]=0;

        for(int i=1;i<prices.size();i++){
            dp[i]=max(dp[i-1],prices[i]-minCost);
            minCost=min(minCost,prices[i]);
        }
        
        return dp[prices.size()-1];
    }
};
// @lc code=end

