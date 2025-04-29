/*
 * @lc app=leetcode.cn id=2962 lang=cpp
 *
 * [2962] 统计最大元素出现至少 K 次的子数组
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        long long cnt=0;
        int max=INT32_MIN;
        for(auto it:nums){
            max=it>max?it:max;
        }

        int left=0,right=0;
        for(right=0;right<nums.size();right++){
            if(nums[right]==max){
                cnt++;
            }
            while(cnt==k&&left<=right){
                if(nums[left]==max)
                    cnt--;
                left++;
            }
            ans+=left;
        }
        return ans;
    }
};
// @lc code=end

