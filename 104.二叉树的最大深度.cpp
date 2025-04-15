/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxLength=INT32_MIN;
    int length=0;
    void tarv(TreeNode* node){
        if(node==nullptr){
            maxLength=max(maxLength,length);
            return ;
        }
        length++;
        tarv(node->left);
        length--;
        length++;
        tarv(node->right);
        length--;
        return ;
    }
public:
    int maxDepth(TreeNode* root) {
        tarv(root);
        return maxLength;
    }
};
// @lc code=end

