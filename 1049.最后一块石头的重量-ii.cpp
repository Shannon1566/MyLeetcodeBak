/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        for(auto it:stones){
            sum+=it;
        }
        int target=sum/2;

        vector<int> dp(target+1,0);
        // dp[j]: 容量为j的背包最多能装多重的石头
        
        for(int i=0;i<stones.size();i++){
            // 先物品，后背包
            for(int j=target;j>=stones[i];j--){
                dp[j]=max(dp[j],dp[j-stones[i]]+stones[i]);
            }
        }

        return sum-2*dp[target];
    }
};
// @lc code=end

