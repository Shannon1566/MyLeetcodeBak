/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum=0;
        int totalSum=0;
        int strat=0;
        for (int i=0;i<gas.size();i++){
            totalSum+=gas[i]-cost[i];
            curSum+=gas[i]-cost[i];
            if (curSum<0){
                curSum=0;
                strat=i+1;
            }
        }
        if(totalSum<0) return -1;
        else return strat;
    }
};
// @lc code=end

