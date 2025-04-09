/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums,int startIndex,vector<int>& used){
        result.emplace_back(path);
        for (int i = startIndex; i < nums.size(); i++){
            if(i>0&&nums[i-1]==nums[i]&&used[i-1]==false)continue; 
            path.push_back(nums[i]);
            used[i]=true;
            backtracking(nums,i+1,used);
            path.pop_back();
            used[i]=false;
        }
        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(),nums.end());
        vector<int> used(nums.size(),false);
        backtracking(nums,0,used);
        return result;
    }
};
// @lc code=end
