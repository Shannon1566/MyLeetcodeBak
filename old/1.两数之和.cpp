/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include "0.h"
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashMap;
        vector<int> ans(2);
        for(int i=0;i<nums.size();i++){
            auto it=hashMap.find(nums[i]);
            if(it!=hashMap.end()){
                ans[0]=i;
                ans[1]=it->second;
                return ans;
            }
            hashMap.emplace(target-nums[i],i);
        }
        return ans;
    }
};
// @lc code=end

