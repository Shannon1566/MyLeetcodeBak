/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        //dp[j]:总和零钱为j的时候，找钱方案最少时，需要的硬币数量
        for(int i=0;i<coins.size();i++){//物品
            for(int j=coins[i];j<=amount;j++){//背包
                if(dp[j-coins[i]]==INT_MAX) continue;
                dp[j]=min(dp[j],dp[j-coins[i]]+1);
            }
        }
        if(dp[amount]==INT_MAX) return -1;
        else return dp[amount];
    }
};
// @lc code=end
int main(){
    Solution sol;
    vector<int> coins{2};
    sol.coinChange(coins,3);
    return 0;
}
