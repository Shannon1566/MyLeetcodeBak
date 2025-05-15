/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // vector<vector<uint64_t>> dp(coins.size(),vector<uint64_t>(amount+1,0));
        // // 能找钱的种类
        // for(int j=0;j<=amount;j++){
        //     if (j%coins[0]==0) dp[0][j]=1;
        // }
        // for(int i=0;i<coins.size();i++){
        //     dp[i][0]=1;
        // }

        // for(int i=1;i<coins.size();i++){
        //     for(int j=0;j<=amount;j++){
        //         if(coins[i]>j) 
        //             dp[i][j]=dp[i-1][j];
        //         else 
        //             dp[i][j]=dp[i-1][j]+dp[i][j-coins[i]];
        //     }
        // }
        // return dp[coins.size()-1][amount];

        vector<uint64_t> dp(amount+1,0);
        dp[0]=1;
        // 外层物品 内层背包 组合数
        // 内层背包 外层物品 排列数
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j]+=dp[j-coins[i]];
            }
        }
        return dp[amount];


    }
};
// @lc code=end

