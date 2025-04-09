/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end(),cmp);
        result.emplace_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(result.back()[1]>=intervals[i][0]){
                result.back()[1]=max(result.back()[1],intervals[i][1]);
            }else{
                result.emplace_back(intervals[i]);
            }
        }
        return result;
    }
};
// @lc code=end

