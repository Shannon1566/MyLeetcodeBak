/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // s[j]-s[i]==nums[i]+...+nums[j-1]
        vector<int> presum(nums.size(),0);
        presum[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            presum[i]=presum[i-1]+nums[i];
        }

        int ans=0;
        unordered_map<int,int> hashMap{{0,1}};
        for(int i=0;i<nums.size();i++){
            auto it=hashMap.find(presum[i]-k);
            if(it!=hashMap.end())
                ans+=hashMap[presum[i]-k];
            hashMap[presum[i]]++;
        }
        return ans;
    }
};
// @lc code=end

