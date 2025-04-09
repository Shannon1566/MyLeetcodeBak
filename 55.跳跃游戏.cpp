/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include"0.cpp"
// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover=0;
        for(int i=0;i<nums.size();i++){
            if (cover>=i){
            cover=max(cover,nums[i]+i);
            }
        }
        return cover>=nums.size()-1;
    }
};
// @lc code=end

