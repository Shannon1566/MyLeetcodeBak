/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> & nums,int startIndex){
        result.emplace_back(path);
        for (int i=startIndex;i<nums.size();i++){
            path.emplace_back(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
        return;

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums,0);
        return result;
    }
};
// @lc code=end

