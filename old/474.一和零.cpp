/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */
#include "0.h"
// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // i j 容量的背包装了多少个物品
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0]=0;
        for(auto str:strs){
            int x=0,y=0;
            for(auto ch:str){
                if(ch=='0') x++;
                else y++;
            }
            for(int i=m;i>=x;i--)
                for(int j=n;j>=y;j--)
                    dp[i][j]=max(dp[i-x][j-y]+1,dp[i][j]);
        }
        return dp[m][n];
    }
};
// @lc code=end

