/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    TreeNode* pre=NULL;
    int min=INT32_MAX;
    void trav(TreeNode* cur){

        if (!cur) return ;  
        trav(cur->left);
        if(pre)
            if (abs(cur->val-pre->val)<min) min=abs(cur->val-pre->val);
        pre =cur;
        trav(cur->right);
        return;
    }

    
    int getMinimumDifference(TreeNode* root) {
        trav(root);
        return min;
    }
};
// @lc code=end

