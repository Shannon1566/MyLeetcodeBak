/*
 * @lc app=leetcode.cn id=2364 lang=cpp
 *
 * [2364] 统计坏数对的数目
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> hashMap;
        long long n=nums.size();
        long long cnt=0;
        for(int i=0;i<n;i++){
            int curNum=nums[i]-i;
            cnt+=hashMap[curNum];
            hashMap[curNum]++;
        }
        cnt=n*(n-1)/2-cnt;
        return cnt;
    }
};
// @lc code=end

