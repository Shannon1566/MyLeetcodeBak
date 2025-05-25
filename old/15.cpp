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
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-2;i++){
            int left=i+1,right=nums.size()-1;
            if(i>=1&&nums[i]==nums[i-1]) continue;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==0){
                    ans.emplace_back(vector<int>{nums[i],nums[left],nums[right]});
                    while(left<right&&nums[left]==nums[left+1]) left++;
                    while(left<right&&nums[right]==nums[right-1]) right--;
                    left++;
                    right--;
                }else if(sum>0){
                    right--;
                }else{
                    left++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution sol;
    auto num=vector<int>{-1,0,1,2,-1,-4};
    sol.threeSum(num);
    return 0;
}