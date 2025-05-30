/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left+(right-left)/2;
            if (nums[mid]>=target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
        
    }
};
// @lc code=end
