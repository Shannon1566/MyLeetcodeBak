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
public:
    int maxT(TreeNode* root){
        if (root==NULL) return INT32_MIN;
        int result=root->val;
        result=max(result,maxT(root->left));
        result=max(result,maxT(root->right));
        return result;
    }
    int minT(TreeNode* root){
        if (root==NULL) return INT32_MAX;
        int result=root->val;
        result=min(result,minT(root->left));
        result=min(result,minT(root->right));
        return result;
    }
    bool isValidBST(TreeNode* root) {
        if (root==NULL) return true;
        bool result=true;
        if (root->left&& maxT(root->left)>=root->val) return false;
        if (root->right&& minT(root->right)<=root->val)return false;

        return result&&isValidBST(root->left)&&isValidBST(root->right);
    }
};
// @lc code=end

