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
        int target=0;
        for(auto it:nums) target+=it;
        if(target%2==1) return false;
        target=target/2;
        vector<int> dp(target+1,0);
        dp[0]=0;
        for(int i=0;i<nums.size();i++){
            for(int j=target;j>=nums[i];j--){
                dp[j]=max(dp[j],dp[j-nums[i]]+nums[i]);
            }
            if(dp[target]==target) return true;
        }
        return false;

    }
};
// @lc code=end

