/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    TreeNode* trav(TreeNode* node){
        if(node==nullptr) 
            return nullptr;
        TreeNode* newLeft=trav(node->right);
        TreeNode* newRight=trav(node->left);
        node->left=newLeft;
        node->right=newRight;
        return node;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        return trav(root);
    }
};
// @lc code=end

