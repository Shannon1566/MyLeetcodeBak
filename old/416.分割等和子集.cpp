/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target=0;
        for (int i=0;i<nums.size();i++){
            target+=nums[i];
        }
        if (target % 2==1) return false;
        target=target/2;

        vector<int> dp(10001,0);
        // dp[j]: 容量为i的背包，塞入数字的最大和为多少

        for(int i=0;i<nums.size();i++){//物品
            for(int j=target;j>=nums[i];j--){
                dp[j]=max(dp[j],dp[j-nums[i]]+nums[i]);
            }
        }

        return dp[target]==target;
    }
};
// @lc code=end

