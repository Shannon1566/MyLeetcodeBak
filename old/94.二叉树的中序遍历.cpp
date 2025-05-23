/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> result;
    void trav(TreeNode* node){
        if(node==nullptr) return ;
        trav(node->left);
        result.emplace_back(node->val);
        trav(node->right);
        return ;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        trav(root);
        return result;
    }
};
// @lc code=end

