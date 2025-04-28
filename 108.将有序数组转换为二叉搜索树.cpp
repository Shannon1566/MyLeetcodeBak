/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */
#include "0.cpp"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* trav(vector<int>& nums,int l,int r){
        if(l==r)
            return nullptr;
        int m=l+(r-l)/2;
        return new TreeNode(nums[m],trav(nums,l,m),trav(nums,m+1,r));
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return trav(nums,0,nums.size());
    }
};
// @lc code=end

