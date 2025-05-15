/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include "0.cpp"
// @lc code=start
class Solution {
    int robRange(vector<int>& nums,int start,int end){
        if(start==end) return nums[start];
        vector<int> dp(nums.size());
        dp[start]=nums[start];
        dp[start+1]=max(nums[start],nums[start+1]);
        for(int i=start+2;i<=end;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[end];
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n);
        return max(robRange(nums,0,nums.size()-2),robRange(nums,1,nums.size()-1));
    }
};
// @lc code=end

