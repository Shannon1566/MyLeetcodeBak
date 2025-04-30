/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include "0.cpp"
// @lc code=start
class Solution {
    int getLeftBorder(vector<int>& nums,int target){
        int left=0,right=nums.size()-1;
        // 核心思想：[left,right]是我们应该需要处理的区间，还没有染色的区间！
        // 小于目标值 染红色，大于等于目标值 染蓝色
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]<target){
                left=mid+1; 
            }else{
                right=mid-1;
            }
        }
        return left;
        // 染色结束，[0,right]都是红色 [left,n]都是蓝色
    }
    int getRightBorder(vector<int>& nums,int target){
        int left=0,right=nums.size()-1;
        // 大于目标值 蓝色，小于等于目标值 红色，
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]<=target){
                left=mid+1; 
            }else{
                right=mid-1;
            }
        }
        return right;
        // 染色结束，[0,right]都是红色 [left,n]都是蓝色
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBorder=getLeftBorder(nums,target);
        int rightBorder=getRightBorder(nums,target);
        if(leftBorder>rightBorder)
            return {-1,-1};
        else
            return {leftBorder,rightBorder};
    }
};
// @lc code=end

