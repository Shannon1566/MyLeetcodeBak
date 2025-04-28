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
        vector<int> pre(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            pre[i+1]=pre[i]+nums[i];
        }

        int ans=0;
        unordered_map<int,int> cnt;
        for(auto it :pre){
            ans+=cnt.find(it-k)!=cnt.end()?cnt[it-k]:0;
            cnt[it]++;
        }
        return ans;
    }
};
// @lc code=end

