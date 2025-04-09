/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
        if ((long long)(node->val-p->val)*(node->val-q->val)<=0) return node;
        else{
            if(node->val>p->val){
                return trav(node->left,p,q);
            }else{
                return trav(node->right,p,q);
            }
        }

    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        return trav(root, p, q);
    }
};
// @lc code=end
