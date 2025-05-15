/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-2;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]<nums[mid+1]){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return l;
    }
};
// @lc code=end

