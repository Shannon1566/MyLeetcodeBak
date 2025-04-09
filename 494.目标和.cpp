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
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int left=(target+sum)/2;
        if ((target+sum)%2==1) return 0;
        if (abs(target)>sum) return 0;
        vector<int> dp(1001,0);
        // 容量为j的背包装满有多少种方法

        dp[0]=1;
        for(int i=0;i<nums.size();i++){//物品
            for(int j=left;j>=nums[i];j--){//背包
                dp[j]+=dp[j-nums[i]];
            }
        }
        return dp[left];

    }
};
// @lc code=end

