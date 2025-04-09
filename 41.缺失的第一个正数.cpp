/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
#include "0.cpp"
// @lc code=start
class Solution {
private:
    void swap(vector<int>& nums,int a,int b){
        int tmp=nums[a];
        nums[a]=nums[b];
        nums[b]=tmp;
        return ;
    }
public:
    int firstMissingPositive(vector<int>& nums) {
        // unordered_set<int> hashSet;
        // for(int i=0;i<nums.size();i++){
        //     hashSet.emplace(nums[i]);
        // }
        // for(int i=1;i<=INT32_MAX;i++){
        //     if(hashSet.find(i)==hashSet.end())
        //         return i;
        // }
        // return -1;
        for(int i=0;i<nums.size();i++){
            while(nums[i]>=1&&nums[i]<=nums.size()&&nums[nums[i]-1]!=nums[i]){
                swap(nums,i,nums[i]-1);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1) return i+1;
        }
        return nums.size()+1;
    }
};
// @lc code=end

