/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size()){
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==0){
                    vector<int> result{nums[i],nums[left],nums[right]};
                    results.emplace_back(result);
                    do{
                        right--;
                    }while(right>=left&&nums[right+1]==nums[right]);
                    do{
                        left++;
                    }while(left<=right&&nums[left-1]==nums[left]);
                }else if(sum>0){
                    do{
                        right--;
                    }while(right>=left&&nums[right+1]==nums[right]);
                        
                }else if(sum<0){
                    do{
                        left++;
                    }while(left<=right&&nums[left-1]==nums[left]);
                        
                }
            }
            do{
                i++;
            }while(i<nums.size()&&nums[i-1]==nums[i]);
        }
        return results;
    }
};
// @lc code=end
int main(){
    Solution sol;
    vector<int> nums{-1,0,1,2,-1,-4};
    sol.threeSum(nums);
    return 0;
}
