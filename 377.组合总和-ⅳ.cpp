/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<__int128>dp(target+1,0);
        dp[0]=1;
        // dp[j]:能够组成目标为j的【组合】个数
        for(int j=0;j<=target;j++){//背包
            for(int i=0;i<nums.size();i++){//物品
                if(j-nums[i]>=0)
                    dp[j]+=dp[j-nums[i]];
            }
        }
        return dp[target];
    }
};
// @lc code=end

