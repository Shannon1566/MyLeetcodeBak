/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backtracing(int begin,int sum,int n,int k){
        if (sum==n&&path.size()==k) {
            result.emplace_back(path);
            return;
        }

        for(int i=begin;i<=9;i++){
            sum+=i;
            path.emplace_back(i);
            backtracing(i+1,sum,n,k);
            sum-=i;
            path.pop_back();
        }
        return ;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracing(1,0,n,k);
        return result;
    }
};
// @lc code=end

