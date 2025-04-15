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
public:
    TreeNode* build(vector<int>& nums,int begin,int end){
        // [begin,end)
        if(begin>=end) return NULL;
        int mid=(begin+end)/2;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=build(nums,begin,mid);
        node->right=build(nums,mid+1,end);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums,0,nums.size());
    }
};
// @lc code=end

