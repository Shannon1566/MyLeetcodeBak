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
        vector<int> dp(n+1);
        // 整数为n的最大拆解乘积
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=0;
            for(int j=1;j<=i;j++){
                dp[i]=max(dp[i],max((i-j)*j,dp[i-j]*j));
            }
        }
        return dp[n];
    }
};
// @lc code=end

int main(){
    Solution sol;
    sol.integerBreak(4);
    return 0;
}