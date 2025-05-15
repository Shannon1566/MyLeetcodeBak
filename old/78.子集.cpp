/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include "0.cpp"
// @lc code=start
class Solution {
    vector<vector<int>> result;
    vector<int> path;
    void dfs(vector<int>& nums,int startIndex){
        result.emplace_back(path);
        for(int i=startIndex;i<nums.size();i++){
            path.push_back(nums[i]);
            dfs(nums,i+1);
            path.pop_back();
        }
        return ;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums,0);
        return result;
    }
};
// @lc code=end

