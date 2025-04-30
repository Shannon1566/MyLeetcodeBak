/*
 * @lc app=leetcode.cn id=1295 lang=cpp
 *
 * [1295] 统计位数为偶数的数字
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(auto it:nums){
            while(it>=100){
                it=it/100;
            }
            cnt+=it>=10;
        }
        return cnt;
    }
};
// @lc code=end

