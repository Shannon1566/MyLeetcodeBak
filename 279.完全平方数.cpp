/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        // 先物品 后背包 组合数
        // 先背包 后物品 排列数
        for(int i=1;i*i<=n;i++){
            for(int j=i*i;j<=n;j++){
                dp[j] =min(dp[j-i*i]+1,dp[j]);
            }
        }
        return dp[n];
    }
};
// @lc code=end

