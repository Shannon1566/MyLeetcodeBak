/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int result=INT32_MIN;
        int head=0;
        int tail=0;
        // [head,tail]
        for(int tail=0;tail<nums.size();tail++){
            sum+=nums[tail];
            result=max(result,sum);
            if(sum<0){
                head=tail+1;
                sum=0;
                continue;
            }
        }
        return result;
    }
};
// @lc code=end

