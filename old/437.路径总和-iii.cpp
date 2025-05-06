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
    int dfs(TreeNode* node, long long currentSum, int targetSum, unordered_map<long long, int>& cnt) {
        if (node == nullptr) {
            return 0;
        }

        currentSum += node->val;
        int res = 0;
        if (cnt.count(currentSum - targetSum)) {
            res += cnt[currentSum - targetSum];
        }

        cnt[currentSum]++;
        res += dfs(node->left, currentSum, targetSum, cnt);
        res += dfs(node->right, currentSum, targetSum, cnt);
        cnt[currentSum]--; // 回溯

        return res;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> cnt;
        cnt[0] = 1; // 前缀和为 0 出现一次
        return dfs(root, 0, targetSum, cnt);
    }


    
};

// @lc code=end

