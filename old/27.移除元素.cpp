/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include "0.h"
// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fast=0,slow=0;
        for(fast=0;fast<nums.size();fast++){
            if(nums[fast]==val) continue;
            else{
                nums[slow]=nums[fast];
                slow++;
            }
        }
        return slow;
    }
};
// @lc code=end

