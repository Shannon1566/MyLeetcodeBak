/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==0) return 0;
        vector<int> dp(n);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];

    }
};
// @lc code=end

