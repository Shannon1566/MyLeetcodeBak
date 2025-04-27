/*
 * @lc app=leetcode.cn id=1512 lang=cpp
 *
 * [1512] 好数对的数目
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int ,int> map;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            cnt+=map[nums[i]];
            map[nums[i]]++;
        }
        return cnt;
    }
};
// @lc code=end

