/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int cnt=0;
    unordered_map<long long ,int> hashMap{{0,1}};
    void dfs(TreeNode* node,int targetSum,long long sum){
        if (node==nullptr) return ;
        sum+=node->val;
        auto it = hashMap.find(sum-targetSum);
        if(it!=hashMap.end()){
            cnt+=hashMap[sum-targetSum];
        }
        hashMap[sum]++;
        dfs(node->left,targetSum,sum);
        dfs(node->right,targetSum,sum);
        hashMap[sum]--;
        return ;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum,0);
        return cnt;
    }
};
// @lc code=end

