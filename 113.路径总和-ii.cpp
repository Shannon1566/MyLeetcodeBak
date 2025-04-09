/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */
#include"0.leetcode.cpp"
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
    vector<vector<int>> result;
    vector<int> path;
    void trav(TreeNode* node,int sum){
        path.emplace_back(node->val);
        if(node->left==NULL&&node->right==NULL){
            if(sum-node->val==0){
                result.emplace_back(path);
            }
            path.pop_back();
            return;
        }
        if(node->left){
            trav(node->left,sum-node->val);
        }
        if(node->right){
            trav(node->right,sum-node->val);
        }
        path.pop_back();
        return;

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root==NULL) return result;
        trav(root,targetSum);
        return result;
    }
};
// @lc code=end

