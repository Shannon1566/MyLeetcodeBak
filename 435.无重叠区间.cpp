/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */
#include "0.cpp"
// @lc code=start
class Solution {
    static bool cmp(vector<int> &a,vector<int> &b){

        return a[0]<b[0];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size()==1) return 0;
        sort(intervals.begin(),intervals.end(),cmp);
        int count=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<intervals[i-1][1]){
                count++;
                intervals[i][1]=min(intervals[i][1],intervals[i-1][1]);
            }
        }
        return count;
    }
};
// @lc code=end

