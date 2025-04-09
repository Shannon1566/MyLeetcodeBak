/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    int sum=0;
    void backtracing(vector<int>& candidates,int target,int stratIndex){
        if (sum==target){
            result.emplace_back(path);
            return;
        }else{
            for(int i=stratIndex;i<candidates.size()&&sum+candidates[i]<=target;i++){
                sum+=candidates[i];
                path.emplace_back(candidates[i]);
                backtracing(candidates,target,i);
                sum-=candidates[i];
                path.pop_back();
            }
            return;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtracing(candidates,target,0);
        return result;
    }
};
// @lc code=end

