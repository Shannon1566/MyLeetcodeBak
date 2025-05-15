/*
 * @lc app=leetcode.cn id=2176 lang=cpp
 *
 * [2176] 统计数组中相等且可以被整除的数对
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int cnt=0;
        unordered_multimap<int,int> hashMap;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]&&(i*j)%k==0)
                    cnt++;
            }
        }        
        return cnt;
    }
};
// @lc code=end

