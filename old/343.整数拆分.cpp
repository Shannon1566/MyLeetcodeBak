/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        // 拆分i的最大结果
        vector<int> dp(n+1,0);
        dp[2]=1;
        for(int i=3;i<=n;i++){
            for(int j=1;j<=i/2;j++){
                dp[i]=max(dp[i],max(j*dp[i-j],j*(i-j)));
            }
        }
        return dp[n];
    }
};
// @lc code=end

