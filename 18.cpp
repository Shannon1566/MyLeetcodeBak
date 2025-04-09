/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        
        vector<vector<int>> result;
        if (n<4) return result;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < n; i++)
        {
            if (i>0&&nums[i-1]==nums[i])continue;
            if (nums[i]>target&&nums[i]>0) break;
            for (int j = i+1; j < n; j++)
            {
                if (j>i+1&&j<n-2&&nums[j-1]==nums[j])continue;
                if (nums[i]+nums[j]>target&&nums[i]+nums[j]>0);
                int left=j+1;
                int right=n-1;
                while (left<right){
                    if((long)nums[i]+nums[j]+nums[left]+nums[right]==target){
                        vector<int> ijleftright= {nums[i],nums[j],nums[left],nums[right]};
                        result.emplace_back(ijleftright);
                        while(left<right&&nums[left]==nums[left+1]) left++;
                        while(left<right&&nums[right]==nums[right-1]) right--;
                        left++;
                        right--;
                        continue;
                    }else if ((long)nums[i]+nums[j]+nums[left]+nums[right]>target){
                        right--;
                    }else{
                        left++;
                    }
                }


            }
            
        }
        return result;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<int> nums={0,0,0,0};
    sol.fourSum(nums,0);
    return 0;
}