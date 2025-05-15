/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-2;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]<nums[nums.size()-1]){
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return nums[l];
    }
};
// @lc code=end

