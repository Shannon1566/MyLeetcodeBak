/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include "0.cpp"
// @lc code=start
class Solution {
    vector<vector<int>> results;
    vector<int> path;
    void dfs(vector<int>& nums,int startIndex,vector<bool>& used){
        if(path.size()==nums.size()){
            results.emplace_back(path);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            path.push_back(nums[i]);
            used[i]=true;
            dfs(nums,i+1,used);
            used[i]=false;
            path.pop_back();
        }
        return ;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        dfs(nums,0,used);
        return results;
    }
};
// @lc code=end

