/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            int n=nums.size();
            vector<vector<int>> result;
            for (int i=0;i<n;i++){
    
                if (nums[i]>0) return result;
    
                while(i>0 &&i<n&& nums[i-1]==nums[i]) i++;
    
                int left=i+1;
                int right=n-1;
    
                while(left<right){
                    if (nums[i]+nums[left]+nums[right]==0){
                        vector<int> ileftright={nums[i],nums[left],nums[right]};
                        result.emplace_back(ileftright);
                        while(right>left&&nums[right]==nums[right-1]) right--;
                        while(right>left&&nums[left]==nums[left+1]) left++;
                        right--;
                        left++;
                        
                    }else if (nums[i]+nums[left]+nums[right]>0){
                        right--;                   
                    }else{
                        left++;
                    }
                }
                
            }
            return result;
    
        }
    };
// @lc code=end

int main(){
    Solution solution;
    vector<int> nums={0,0,0};
    solution.threeSum(nums);
    return 0;
}