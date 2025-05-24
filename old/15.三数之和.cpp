/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include "0.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int left,right;
        for(int i=0;i<nums.size()-2;i++){
            left=i+1;
            right=nums.size()-1;

            if(i>0&&nums[i]==nums[i-1])
                continue;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==0){
                    ans.emplace_back(vector<int>{nums[i],nums[left],nums[right]});
                    while(right>left&&nums[left]==nums[left+1])
                        left++;
                    while(right>left&&nums[right]==nums[right-1])
                        right--;
                    right--;
                    left++;
                }
                    
                else if(sum>0)
                    right--;
                else
                    left++;
            }
        }
        return ans;
    }
};
// @lc code=end

