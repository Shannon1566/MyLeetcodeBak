/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include "0.h"
// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int left = 0, right = 0;
        int sum = 0;
        int ans = INT32_MAX;
        for (right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
                
            }
        }
        if(ans==INT32_MAX) return 0;
        else return ans;
    }
};
// @lc code=end
