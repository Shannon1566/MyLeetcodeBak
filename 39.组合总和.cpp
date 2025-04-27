/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include "0.cpp"
// @lc code=start
class Solution {
    int sum=0;
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int>& candidates, int target, int startIndex){
        if(sum>target)
            return ;
        if(sum==target){
            result.emplace_back(path);
            return ;
        }
        for(int i=startIndex;i<candidates.size();i++){
            sum+=candidates[i];
            path.emplace_back(candidates[i]);
            backtracking(candidates,target,i);
            path.pop_back();
            sum-=candidates[i];
        }
        return ;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates,target,0);
        return result;
    }
};
// @lc code=end

