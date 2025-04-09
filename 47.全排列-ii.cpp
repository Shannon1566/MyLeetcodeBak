/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, vector<bool> &used) {
        if (path.size() == nums.size()) {
            result.emplace_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) continue;
            if (i>0&&nums[i-1]==nums[i]&&used[i-1]==false) continue;
            used[i] = true;
            path.emplace_back(nums[i]);
            backtracking(nums, used);
            used[i] = false;
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};
// @lc code=end
