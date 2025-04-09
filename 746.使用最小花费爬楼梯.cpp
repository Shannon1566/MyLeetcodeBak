/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // 爬上n台阶最小需要的体力花费
        vector<int> dp(cost.size()+1,INT_MAX);
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=cost.size();i++){
            dp[i]=min(cost[i-1]+dp[i-1],cost[i-2]+dp[i-2]);
        }
        return dp[cost.size()];
    }
};
// @lc code=end

