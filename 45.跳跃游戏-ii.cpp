/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,INT32_MAX);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<=nums[i]&&i+j<n;j++){
                dp[i+j]=min(dp[i+j],dp[i]+1);
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

