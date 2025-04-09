/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    TreeNode *pre = NULL;
    vector<int> result;
    int maxCount = 0;
    int count = 0;
    void trav(TreeNode *node) {

        if (node == NULL) return;

        trav(node->left);

        if (pre) {
            if (pre->val==node->val) count++;
            else count=1;
        }else{
            count=1;
        }

        if (count>maxCount){
            maxCount=count;
            result.clear();
            result.emplace_back(node->val);
        }else if(count==maxCount){
            result.emplace_back(node->val);
        }

        pre = node;

        trav(node->right);

        return;
    }
    vector<int> findMode(TreeNode *root) {
        trav(root);
        return result;
    }
};
// @lc code=end
