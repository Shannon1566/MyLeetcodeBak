/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool trav(TreeNode* l,TreeNode* r){
        if(l==nullptr||r==nullptr)
            return l==r;
        return (l->val==r->val)&&trav(l->left,r->right)&&trav(l->right,r->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return trav(root->left,root->right);
    }
};
// @lc code=end

