/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValid(TreeNode* root,long long left=LONG_LONG_MIN,long long right=LONG_LONG_MAX){
        if (root==nullptr)
            return true;
        long long x= root->val;
        return left<x&&x<right&&isValid(root->left,left,x)&&isValid(root->right,x,right);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root);
    }
};
// @lc code=end

