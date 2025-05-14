/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex=0;
        for(int i=0;i<nums.size();i++){
            if(maxIndex<i) return false;
            maxIndex=max(maxIndex,i+nums[i]);
        }
        return true;
    }
};
// @lc code=end

