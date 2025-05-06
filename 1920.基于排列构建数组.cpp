/*
 * @lc app=leetcode.cn id=1920 lang=cpp
 *
 * [1920] 基于排列构建数组
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            ans[i]=nums[nums[i]];
        }
        return ans;
    }
};
// @lc code=end

