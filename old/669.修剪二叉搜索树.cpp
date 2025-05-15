/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==NULL) return NULL;
        if(root->val<low){
            auto rightChild=trimBST(root->right,low,high);
            return rightChild;  
        }
        if(root->val>high){
            auto leftChild=trimBST(root->left,low,high);
            return leftChild;
        }
        root->left=trimBST(root->left,low,high);
        root->right=trimBST(root->right,low,high);
        return root;
    }
};
// @lc code=end

