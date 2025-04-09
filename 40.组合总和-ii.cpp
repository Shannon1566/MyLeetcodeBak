/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    int sum=0;
    void backtracking(vector<int>& candidates, int target,int startIndex,vector<bool>& used){
        if(sum>target) return;
        if(sum==target){
            result.emplace_back(path);
            return;
        }
        for(int i=startIndex;i<candidates.size();i++){
            if(i>0&&candidates[i]==candidates[i-1]&&used[i-1]==false) continue;
            sum+=candidates[i];
            path.emplace_back(candidates[i]);
            used[i]=true;
            backtracking(candidates,target,i+1,used);
            used[i]=false;
            path.pop_back();
            sum-=candidates[i];
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<bool> used(candidates.size(),false);
        backtracking(candidates,target,0,used);
        return result;
    }
};
// @lc code=end

