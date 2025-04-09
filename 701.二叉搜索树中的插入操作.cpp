/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    TreeNode *trav(TreeNode *node, int val) {
        if (node == NULL) {
            return new TreeNode(val);
        }else{
            if (node->val<val){
                node->right=trav(node->right,val);
            }else{
                node->left=trav(node->left,val);
            }
            return node;
        }
    }
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        return trav(root, val);
    }
};
// @lc code=end
