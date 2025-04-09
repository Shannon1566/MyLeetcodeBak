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
        vector<int> dp(n+1,INT_MAX);//组成n的最小平方数的数量
        //组合数，先物品，再背包
        dp[0]=0;
        for(int i=0;i*i<=n;i++){
            for(int j=i*i;j<=n;j++){
                if(dp[j-i*i]==INT_MAX) continue;
                dp[j]=min(dp[j],dp[j-i*i]+1);
            }
        }
        return dp[n];
    }
};
// @lc code=end

