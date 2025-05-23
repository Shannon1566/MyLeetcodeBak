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
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0]=0;
        for(string str:strs){
            int cnt0=0,cnt1=0;
            for(char ch:str){
                if(ch=='0') cnt0++;
                else cnt1++;
            }
            for(int i=m;i>=cnt0;i--){
                for(int j=n;j>=cnt1;j--){
                    dp[i][j]=max(dp[i][j],dp[i-cnt0][j-cnt1]+1);
                }
            }
        }
        return dp[m][n];        
    }
};
// @lc code=end

