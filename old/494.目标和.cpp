/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */
#include "0.h"
// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto it:nums) sum+=it;
        if((sum+target)%2==1) return 0;
        if(abs(target)>sum) return 0;
        int left=(sum+target)/2;
        
        vector<int> dp(left+1,0);
        dp[0]=1;
        for(int i=0;i<nums.size();i++){
            for(int j=left;j>=nums[i];j--){
                dp[j]+=dp[j-nums[i]];
            }
        }
        return dp[left];
    }
};
// @lc code=end

