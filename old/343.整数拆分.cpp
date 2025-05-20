/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */
#include "0.h"
// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        // i拆分的最大结果
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i]=max((i-j)*j,max(dp[i],dp[i-j]*(j)));
            }
        }
        return dp[n];
    }
};
// @lc code=end

