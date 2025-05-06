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
        vector<int> preSum(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            preSum[i+1]=preSum[i]+nums[i];
        }

        int ans=0;
        unordered_map<int,int> cnt;
        cnt[0]=1;
        for(int i=1;i<preSum.size();i++){
            if(cnt.find(preSum[i]-k)!=cnt.end()){
                ans+=cnt[preSum[i]-k];
                
            }
            cnt[preSum[i]]++;
        }
        return ans;
    }
};
// @lc code=end

