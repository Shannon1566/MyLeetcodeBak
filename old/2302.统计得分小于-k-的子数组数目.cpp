/*
 * @lc app=leetcode.cn id=2302 lang=cpp
 *
 * [2302] 统计得分小于 K 的子数组数目
 */

#include "0.cpp"
// @lc code=start
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long cnt=0;
        long long sum=0;       
        int left=0,right=0;
        for(right=0;right<nums.size();right++){
            sum+=nums[right];
            while(sum*(right-left+1)>=k && left<=right){
                sum-=nums[left];
                left++;
            }
            cnt+=right-left+1;
        }
        return cnt;
    }
};
// @lc code=end

