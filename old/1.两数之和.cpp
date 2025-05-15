/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            auto it=map.find(target-nums[i]);
            if(it!=map.end()){
                result.emplace_back(it->second);
                result.emplace_back(i);
                return result;
            }else{
                map.emplace(nums[i],i);
            }
        }
        return result;
    }
};
// @lc code=end

