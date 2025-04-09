/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT32_MAX);
        dp[0]=0;
        // dp[j] 总金额为j的时候的最少硬币数
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<=amount;j++){
                if (dp[j-coins[i]]!=INT32_MAX)
                dp[j]=min(dp[j - coins[i]] + 1, dp[j]);
            }
        }
        if(dp[amount]==INT32_MAX)return -1;
        else return dp[amount];
    }
};
// @lc code=end

