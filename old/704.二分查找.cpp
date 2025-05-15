/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
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
        // 大于目标值染红色，小于等于目标值染蓝色，
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
    int search(vector<int>& nums, int target) {
        int leftBorder=getLeftBorder(nums,target);
        int rightBorder=getRightBorder(nums,target);
        if(leftBorder==rightBorder) return leftBorder;
        else return -1;
    }
};
// @lc code=end

