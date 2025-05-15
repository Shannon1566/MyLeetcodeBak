/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int maxSum=INT32_MIN;
    int dfs(TreeNode* node){
        if(node==nullptr)
            return 0;
        int left=dfs(node->left);
        int right=dfs(node->right);
        maxSum=max(maxSum,left+right+node->val);
        return max(max(left, right) + node->val, 0);
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
// @lc code=end

