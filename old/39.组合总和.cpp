/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates,int target,int sum,int stratIndex){
        if(sum==target){
            result.emplace_back(path);
            return;
        }
        if(sum>target) return;
        for(int i=stratIndex;i<candidates.size();i++){
            path.emplace_back(candidates[i]);
            backtracking(candidates,target,sum+candidates[i],i);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates,target,0,0);
        return result;
    }
};
// @lc code=end

