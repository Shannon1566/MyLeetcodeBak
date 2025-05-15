/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet{nums.begin(),nums.end()};
        int result=0;
        for(int num:hashSet){
            if(!hashSet.count(num-1)){
                int x=num+1;
                while(hashSet.count(x))x++;
                result=max(result,x-num);
            }
        }
        return result;
    }
};
// @lc code=end

