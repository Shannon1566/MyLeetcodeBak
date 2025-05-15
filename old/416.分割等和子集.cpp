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
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if(sum%2==1)return false;
        int target=sum/2;

        vector<int> dp(target+1,0);
        
        for(int i=0;i<nums.size();i++){
            for(int j=target;j>=nums[i];j--){
                dp[j]=max(dp[j],dp[j-nums[i]]+nums[i]);
                if(dp[target]==target) return true;
            }
        }
        return false;
    }
};
// @lc code=end

