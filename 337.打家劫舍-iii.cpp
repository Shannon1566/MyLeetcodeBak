/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    vector<int> travel(TreeNode* node){
        if(node==nullptr)
            return vector<int>{0,0};
        vector<int> left=travel(node->left);
        vector<int> right=travel(node->right);

        int isRob=node->val+left[0]+right[0];
        int noRob=max(left[0],left[1])+max(right[0],right[1]);

        return vector<int>{noRob,isRob};
    }
public:
    int rob(TreeNode* root) {
        vector<int> result=travel(root);
        return max(result[0],result[1]);
    }
};
// @lc code=end

