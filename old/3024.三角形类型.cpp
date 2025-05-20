/*
 * @lc app=leetcode.cn id=3024 lang=cpp
 *
 * [3024] 三角形类型
 */
#include"0.h"
// @lc code=start
class Solution {
public:
    string triangleType(vector<int>& nums) {
        int minNum=*min_element(nums.begin(),nums.end());
        int maxNum=*max_element(nums.begin(),nums.end());
        int midNum=nums[0]+nums[1]+nums[2]-minNum-maxNum;

        if(minNum+midNum<=maxNum)
            return "none";
        if(minNum==maxNum)
            return "equilateral";
        if(minNum==midNum||maxNum==midNum)
            return "isosceles";
        return "scalene";
    }
};
// @lc code=end

