/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include "0.cpp"
// @lc code=start
class Solution {
    int quickSelect(vector<int>& nums, int k){
        int pivot = nums[rand()%nums.size()];
        vector<int> big ,equal, small;
        for(int num:nums){
            if(num>pivot)
                big.emplace_back(num);
            else if(num<pivot)
                small.emplace_back(num);
            else
                equal.emplace_back(num);
        }

        if(k<=big.size())
            return quickSelect(big,k);
        if(k>big.size()+equal.size())
            return quickSelect(small,k - big.size() - equal.size());
        return pivot;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums,k);
    }
};
// @lc code=end

