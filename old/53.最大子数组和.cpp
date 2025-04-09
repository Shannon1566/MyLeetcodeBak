/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int left=0;
        int sum=0;
        int result=INT_MIN;
        // [left,i]
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            result=sum>result?sum:result;
            if(sum<0) sum=0;
        }
        return result;
    }
};
// @lc code=end

