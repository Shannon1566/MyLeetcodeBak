/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
    bool compare(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL && q != NULL) return false;
        if (p != NULL && q == NULL) return false;

        if (p->val != q->val) return false;
        bool leftCompare = compare(p->left, q->left);
        bool rightCompare = compare(p->right, q->right);
        return leftCompare && rightCompare;
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode *curNode=que.front();
            que.pop();
            if (compare(curNode,subRoot)) {
                return true;
            }else{
                if(curNode->left) que.push(curNode->left);
                if(curNode->right) que.push(curNode->right);
            }
        }
        return false;
    }
};
// @lc code=end
