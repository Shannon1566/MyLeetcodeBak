/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include "0.cpp"
// @lc code=start
class Solution {
public: 
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int begin,int end,int k){
        // [begin,end]
        if(path.size()==k){
            result.emplace_back(path);
            return;
        }
        for(int i=begin;i<=end-(k-path.size())+1;i++){
            path.emplace_back(i);
            backtracking(i+1,end,k);
            path.pop_back();
        }

        return ;
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(1,n,k);
        return result;
    }
};
// @lc code=end

