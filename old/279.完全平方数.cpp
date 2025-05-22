/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include "0.h"
// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT32_MAX);
        dp[0]=0;
        dp[1]=1;
        for(int i=1;i<=n;i++){
            for(int j=i*i;j<=n;j++){
                if(dp[j-i*i]!=INT32_MAX)
                    dp[j]=min(dp[j],dp[j-i*i]+1);
            }
        }
        return dp[n];
    }
};
// @lc code=end

