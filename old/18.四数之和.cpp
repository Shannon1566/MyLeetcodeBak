/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include "0.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int a = 0; a < nums.size(); a++) {
            if (a > 0 && nums[a] == nums[a - 1])
                continue;
            for (int b = a + 1; b < nums.size(); b++) {
                if (b > a + 1 && nums[b] == nums[b - 1])
                    continue;
                int c = b + 1, d = nums.size() - 1;
                while (c < d) {
                    long long sum = (long long)nums[a] + (long long)nums[b] + (long long)nums[c] + (long long)nums[d];
                    if (sum == target) {
                        ans.emplace_back(vector<int>{nums[a], nums[b], nums[c], nums[d]});
                        while (c < d && nums[c] == nums[c + 1])
                            c++;
                        while (c < d & nums[d] == nums[d - 1])
                            d--;
                        c++;
                        d--;
                    } else if (sum > target) {
                        d--;
                    } else {
                        c++;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
