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
        // int n=cost.size();
        // // 爬上i需要的最小花费
        // vector<int> dp(n+1);
        // dp[0]=0;
        // dp[1]=0;
        // for(int i=2;i<=n;i++){
        //     dp[i]=min(dp[i-2]+cost[i-2],dp[i-1]+cost[i-1]);
        // }
        // return dp[n];

        int n=cost.size();
        // 爬上i需要的最小花费
        vector<int> dp(n+1);
        int a=0,b=0,c;
        for(int i=2;i<=n;i++){
            c=min(a+cost[i-2],b+cost[i-1]);
            a=b;
            b=c;
        }
        return b;

    }
};
// @lc code=end

