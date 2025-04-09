/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int bagTarget=(target+sum)/2;

        if ((target + sum) % 2 == 1) return 0; 
        if (abs(target) > sum) return 0;

        // dp[j]:装满容量为j的背包有多少种方法
        vector<int> dp(bagTarget+1,0);
        dp[0]=1;

        for(int i=0;i<nums.size();i++){
            for(int j=bagTarget;j>=nums[i];j--){
                dp[j]+=dp[j-nums[i]];
            }
        }

        return dp[bagTarget];

    }
};
// @lc code=end

