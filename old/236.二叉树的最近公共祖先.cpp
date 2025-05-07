/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */
#include "0.cpp"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *trav(TreeNode *node, TreeNode *p, TreeNode *q) {
        if (node == p) return p;
        if (node == q) return q;
        if (node == NULL) return NULL;

        TreeNode* left=trav(node->left,p,q);
        TreeNode* right=trav(node->right,p,q);
        
        if (left&&right) return node;
        else if (left!=NULL&&right==NULL) return left;
        else if (left==NULL&&right!=NULL) return right;
        else return NULL;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
       
        return  trav(root,p,q);
    }
};
// @lc code=end
