/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */
#include"0.cpp"
// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums,int startIndex){
        if(path.size()>=2){
            result.emplace_back(path);
        }
        if(startIndex==nums.size()) return;
        int uset[201]={0};
        for(int i=startIndex;i<nums.size();i++){
            if((path.size()==0||path[path.size()-1]<=nums[i])&&(uset[nums[i]+100]!=1)){
                uset[nums[i]+100]=1;
                path.emplace_back(nums[i]);
                backtracking(nums,i+1);
                path.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums,0);
        return result;
    }
};
// @lc code=end

