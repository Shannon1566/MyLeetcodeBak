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
    bool isValid(TreeNode* node,long minVal,long maxVal){
        if(node==nullptr) 
            return true;
        if(node->val<=minVal||node->val>=maxVal)
            return false;
        else{
            return isValid(node->left,minVal,node->val)&&isValid(node->right,node->val,maxVal);
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)
            return true;
        return isValid(root,LONG_MIN,LONG_MAX);
    }
};
// @lc code=end

