/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    int sum=0;
    void trav(TreeNode* node){
        if (node==NULL) return;
        trav(node->right);

        sum+=node->val;
        node->val=sum;

        trav(node->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        trav(root);
        return root;
    }
};
// @lc code=end

