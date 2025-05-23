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
        for(int i=1;i<=n;i++){
            for(int j=i*i;j<=n;j++){
                dp[j]=min(dp[j-i*i]+1,dp[j]);
            }
            for(auto it:dp) cout<<it<<' ';
            cout<<endl;
        }
        return dp[n];
    }
};
int main(){
    Solution sol;
    sol.numSquares(12);
    return 0;
}
// @lc code=end

