/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */
#include "0.cpp"
// @lc code=start
class Solution {
private:
    void reverseNum(vector<int>& nums,int head,int tail){
        while(head<tail){
            int tmp=nums[head];
            nums[head]=nums[tail];
            nums[tail]=tmp;
            head++;
            tail--;
        }
        return ;
    }
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        reverseNum(nums,0,nums.size()-1);
        reverseNum(nums,0,k-1);
        reverseNum(nums,k,nums.size()-1);
    }
};
// @lc code=end

