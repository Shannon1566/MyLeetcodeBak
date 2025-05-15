/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(101,vector<int>(101,0));
        // 装满m个1 n个0的背包的最大子集长度
        for(auto str:strs){
            int zeroNum=0,oneNum=0;
            for(int k=0;k<str.size();k++){
                if(str[k]=='0') zeroNum++;
                if(str[k]=='1') oneNum++;
            }
            for (int i=m;i>=zeroNum;i--){
                for (int j=n;j>=oneNum;j--){
                    dp[i][j]=max(dp[i][j],dp[i-zeroNum][j-oneNum]+1);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

