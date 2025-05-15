/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */
#include "0.leetcode.cpp"
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
    bool trav(TreeNode* node,int sum){  
        if (node==NULL) return false;
        sum+=node->val;
        if(node->left==NULL&&node->right==NULL){
            if(sum==0) return true;
            else return false;
        }
        bool leftHas=trav(node->left,sum);
        bool rightHas=trav(node->right,sum);
        return leftHas||rightHas;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=-targetSum;
        return trav(root,sum);
    }
};
// @lc code=end

