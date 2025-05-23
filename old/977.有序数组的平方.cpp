/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
#include "0.h"
// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=n-1;
        vector<int> ans(n);
        for(int j=n-1;j>=0;j--){
            if(nums[left]*nums[left]>nums[right]*nums[right]){
                ans[j]=nums[left]*nums[left];
                left++;
            }else{
                ans[j]=nums[right]*nums[right];
                right--;
            }
        }
        return ans;
    }
};
// @lc code=end

