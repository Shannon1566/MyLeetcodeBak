/*
 * @lc app=leetcode.cn id=3375 lang=cpp
 *
 * [3375] 使数组的值全部为 K 的最少操作次数
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> map(101,0);
        int minNum=INT32_MAX;
        for(auto it:nums){
            map[it]++;
            minNum=min(minNum,it);
        }
        if(minNum<k) return -1;
        int result=0;
        for(int i=100;i>=0;i--){
            if(map[i]==0)
                continue;
            else{
                if(i==k) break;
                result++;
            } 
        }
        return result;
    }
};
// @lc code=end

