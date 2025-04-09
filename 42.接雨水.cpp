/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax(height.size());
        leftMax[0]=height[0];
        for(int i=1;i<height.size();i++){
            leftMax[i]=max(leftMax[i-1],height[i]);
        }
        vector<int> rightMax(height.size());
        rightMax[height.size()-1]=height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<height.size();i++){
            ans+=min(rightMax[i],leftMax[i])-height[i];
        }
        return ans;
    }
};
// @lc code=end

