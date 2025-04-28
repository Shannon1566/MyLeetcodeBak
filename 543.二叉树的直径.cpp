/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int ans=0;
    int dfs(TreeNode* node){
        if(node==nullptr)
            return -1;
        int ll=dfs(node->left);
        int rl=dfs(node->right);
        ans=max(ans,ll+rl+2);
        return max(ll,rl)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;

    }
};
// @lc code=end

