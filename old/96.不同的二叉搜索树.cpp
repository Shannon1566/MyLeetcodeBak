/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */
#include "0.h"
// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<=i-1;j++){
                dp[i]+=dp[j]*dp[i-1-j];
            }
        }
        return dp[n];
    }
};
// @lc code=end

