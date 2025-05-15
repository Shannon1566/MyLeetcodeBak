/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int sum=0;
        int subLength=0;
        int result=INT32_MAX;
        for (int j=0;j<n;j++){
            sum+=nums[j];
            while (sum>=target){
                subLength=j-i+1;
                result=min(subLength,result);
                sum-=nums[i];
                i++;
            }

        }
        return result==INT32_MAX?0:result;
    }
};
// @lc code=end

