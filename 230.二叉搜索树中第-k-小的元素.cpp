/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素
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
    void dfs(TreeNode* node ,int k,int &cnt ,int &ans,bool &hasFind){
        if(node==nullptr||hasFind==true){
            return ;
        }

        dfs(node->left,k,cnt,ans,hasFind);

        cnt++;
        if(cnt==k){
            ans=node->val;
            hasFind=true;
            return ;
        }

        dfs(node->right,k,cnt,ans,hasFind);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans =0;
        int cnt =0;
        bool hasFind=false;
        dfs(root,k,cnt,ans,hasFind);
        return ans;
    }
};
// @lc code=end

