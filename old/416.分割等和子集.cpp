/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
#include "0.h"
// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int targetSum=0;
        for(auto num:nums){
            targetSum+=num;
        }
        if(targetSum % 2==1) return false;
        targetSum=targetSum/2;

        vector<int> dp(targetSum+1,0);
        for(int i=0;i<nums.size();i++){
            for(int j=targetSum;j>=nums[i];j--){
                dp[j]=max(dp[j],dp[j-nums[i]]+nums[i]);
                if(dp[targetSum]==targetSum) return true;
            }
        }
        return false;

    }
};
// @lc code=end

